/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:18 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 13:46:01 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../fdf.h"

void	reset_view(t_view *view);
int		key_hook(int keycode, t_all *all);

#endif /* HOOKS_H */
