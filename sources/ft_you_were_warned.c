/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_you_were_warned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:08:48 by cghael            #+#    #+#             */
/*   Updated: 2020/10/01 19:08:51 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_you_were_warned(t_lemin *lemin)
{
	popen("open 'https://vk.cc/aAmHft'", "r");
	ft_error_n_exit("Ах ты мой шалунишка!\n", lemin, NULL, NULL);
}
