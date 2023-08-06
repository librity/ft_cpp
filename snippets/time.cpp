/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:09:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/08/06 16:58:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c++ -Wall -Wextra -Werror -std=c++98 time.cpp && ./a.out

#include <iostream>
#include <ctime>
#include <cstddef>
#include <cstring>

int main()
{
    std::string dateString = "2023-08-05";
    // std::string dateString = "202-08-05";
    // std::string dateString = "2001-42-42";
    struct tm timeStruct;

    // Initialize the timeStruct to all zeros
    std::memset(&timeStruct, 0, sizeof(timeStruct));

    // Use strptime to parse the date
    const char *format = "%Y-%m-%d";
    const char *dateStr = dateString.c_str();
    char *result = strptime(dateStr, format, &timeStruct);

    // Check if parsing was successful
    if (result == NULL)
    {
        std::cout << "Failed to parse the date.\n";
    }
    else
    {
        // Access the components of the parsed date
        int year = timeStruct.tm_year + 1900; // Years since 1900
        int month = timeStruct.tm_mon + 1;    // Months since January (0-11)
        int day = timeStruct.tm_mday;         // Day of the month (1-31)

        std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
    }

    return 0;
}
