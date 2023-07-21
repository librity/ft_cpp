/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:32 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 18:15:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &form);
    virtual ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);
    virtual ~ShrubberyCreationForm(void);

    virtual void execute(Bureaucrat const &executor) const;

    class OpenFileException : public std::exception
    {
    public:
        const char *what(void) const throw();
    };
};

#define TREES "\
              ,@@@@@@@,\n\
      ,,,.   ,@@@@@@/@@,  .oo8888o.  ,@@@,  .oo8888o.  ,@@@,  .oo8888o.  ,@@@,  .oo88888o0.\n\
   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o,&%%&%&&%,8888\\88/8o,&%%&%&&%,8888\\88/8o,&%%&%&&%,8888\\8'\n\
  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88',%&\\%&&%&&%,88888\\88',%&\\%&&%&&%,88888\\88',%&\\%&&%&&%,88'\n\
  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888',%&&%&%&/%&&%88888',%&&%&%&/%&&%88888',%&&%&%&/%&&%8888'\n\
  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88',%&&%/ %&%%&&@888',%&&%/ %&%%&&@888',%&&%/ %&%%&&@8888'\n\
  `&%\\ ` /%&'    |.|        \\ '|8',`&%\\ ` /%&'  |.|`&%\\ ` /%&'  |.|`&%\\ ` /%&'   `&|.|%\\ `\n\
      |o|        | |         | |      |o|      | |      |o|      | |      |o|      | |\n\
      |.|        | |         | |      |.|      | |      |.|      | |      |.|      | |\n\
\\  \\._\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__\\/ ._\\//_/  ,\\_//__\\/ ._\\//_/  ,\\_//__\\/ ._\\//_/ _//_\n\
"

#endif
