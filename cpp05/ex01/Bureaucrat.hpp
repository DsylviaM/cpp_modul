#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
class Form;
# include "Form.hpp"

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const &getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
