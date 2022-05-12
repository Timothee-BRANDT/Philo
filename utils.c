/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:29:45 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/12 16:27:41 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_is_numeric(char c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

int     ft_atoi(const char *str)
{
        int     i;
        int     result;
        int     negative;

        i = 0;
        result = 0;
        negative = 1;
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
        || str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        negative = -1;
                i++;
        }
        while (str[i] && ft_is_numeric(str[i]))
        {
                result = result * 10 + (str[i] - 48);
                i++;
        }
        return (result * negative);
}