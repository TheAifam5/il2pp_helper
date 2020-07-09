#pragma once

namespace icsaoy {
  /// Exception type for assertion failures
  class assert_exception : public std::exception
  {
  private:
    std::string _expression;
    std::string _file;
    std::string _message;
    std::string _report;
    int _line;

  public:

    /// Helper class for formatting assertion message
    class stream_formatter
    {
    private:

      std::ostringstream _stream;

    public:

      operator std::string() const
      {
        return _stream.str();
      }

      template<typename T>
      stream_formatter& operator << (const T& value)
      {
        _stream << value;
        return *this;
      }
    };

    /// Construct an assertion failure exception
    assert_exception(const char* expression, const char* file, int line, const std::string& message, const std::string& additional = "")
      : _expression(expression)
      , _file(file)
      , _line(line)
      , _message(message)
    {
      std::ostringstream outputStream;

      outputStream << "Exception occured:" << '\n';

      if (!message.empty())
      {
        outputStream << "\tMessage: " << message << '\n';
      }

      if (!_expression.empty())
      {
        outputStream << "\tExpression: ";
        if (_expression == "false" || _expression == "0" || _expression == "FALSE")
        {
          outputStream << "Unreachable code assertion";
        }
        else {
          outputStream << "Assertion '" << expression << "'";
        }
        outputStream << '\n';
      }

      outputStream << "\tFile: " << file << ":" << line << '\n';

      if (!additional.empty()) {
        outputStream << additional;
      }
      _report = outputStream.str();
    }

    assert_exception(const char* file, int line, const std::string& message, const std::string& additional = "")
      : assert_exception("", file, line, message, additional)
    { }

    /// The assertion message
    virtual const char* what() const throw()
    {
      return _report.c_str();
    }

    /// The expression which was asserted to be true
    const char* expression() const throw()
    {
      return _expression.c_str();
    }

    /// Source file
    const char* file() const throw()
    {
      return _file.c_str();
    }

    /// Source line
    int line() const throw()
    {
      return _line;
    }

    /// Description of failure
    const char* message() const throw()
    {
      return _message.c_str();
    }

    ~assert_exception() throw()
    {
    }
  };
}

#define icsaoy_assert_additional() (icsaoy::assert_exception::stream_formatter() << "\tFunction: " << __FUNCTION__ << '\n' << "\tSignature: " << __FUNCSIG__ << '\n')

#define icsaoy_rethrow() std::throw_with_nested(icsaoy::assert_exception(__FILE__, __LINE__, "Exception rethrown", icsaoy_assert_additional()))
#define icsaoy_assert_msg(EXPRESSION, MESSAGE) if(!(EXPRESSION)) { std::throw_with_nested(icsaoy::assert_exception(#EXPRESSION, __FILE__, __LINE__, (icsaoy::assert_exception::stream_formatter() << MESSAGE), icsaoy_assert_additional())); }
#define icsaoy_assert(EXPRESSION) icsaoy_assert_msg(EXPRESSION, "")