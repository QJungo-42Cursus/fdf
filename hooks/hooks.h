/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:18 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 17:08:45 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../fdf.h"

int		close_window(t_all *all);
int		key_hook(int keycode, t_all *all);

#endif /* HOOKS_H */
