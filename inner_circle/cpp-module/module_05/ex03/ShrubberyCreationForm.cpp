/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:58:30 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 15:26:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, Grade(145), Grade(137))
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    return (dynamic_cast<ShrubberyCreationForm&>(AForm::operator=(copy)));
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkExecutable(executor);

    std::ofstream file(this->getName() + "_shrubbery");
    std::string shrubbery = "           *             ,\n"
                            "                       _/^\\_\n"
                            "                      <     >\n"
                            "     *                 /.-.\\         *\n"
                            "              *        `/&\\`                   *\n"
                            "                      ,@.*;@,\n"
                            "                     /_o.I %_\\    *\n"
                            "        *           (`'--:o(_@;\n"
                            "                   /`;--.,__ `')             *\n"
                            "                  ;@`o % O,*`'`&\\\n"
                            "            *    (`'--)_@ ;o %'()\\      *\n"
                            "                 /`;--._`''--._O'@;\n"
                            "                /&*,()~o`;-.,_ `\"\"`)\n"
                            "     *          /`,@ ;+& () o*`;-';\\\n"
                            "               (`\"\"--.,_0 +% @' &()\\\n"
                            "               /-.,_    ``''--....-'`)  *\n"
                            "          *    /@%;o`:;'--,.__   __.'\\\n"
                            "              ;*,&(); @ % &^;~`\"`o;@();         *\n"
                            "              /(); o^~; & ().o@*&`;&%O\\\n"
                            "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
                            "           __.----.(\\-''#####---...___...-----._\n"
                            "         '`         \\)_`\"\"\"\"\"`\n"
                            "                 .--' ')\n"
                            "               o(  )_-\\\n"
                            "                 `\"\"\"` `\n";
    file << shrubbery;
}
