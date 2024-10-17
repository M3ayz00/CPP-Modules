/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileHandling.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:26:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 17:09:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLING_HPP
#define FILEHANDLING_HPP

#include <iostream>
#include <fstream>
#include <string>

int	checkArguments(char **av);
int	checkFile(const std::ifstream &File);


#endif
