/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:10:39 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/20 16:22:26 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# ifdef __linux__
#  define ESC_KEY			65307
#  define A_KEY 			97
#  define S_KEY 			115
#  define D_KEY 			100
#  define W_KEY 			119
#  define Q_KEY 			113
#  define E_KEY 			101
#  define UP				65362
#  define DOWN				65364
#  define LEFT				65361
#  define RIGHT				65363
# endif

# ifdef  __APPLE__
#  define ESC_KEY			53
#  define A_KEY 			0
#  define S_KEY 			1
#  define D_KEY 			2
#  define W_KEY 			13
#  define Q_KEY 			12
#  define E_KEY 			14
#  define UP				126
#  define DOWN				125
#  define LEFT				123
#  define RIGHT				124
# endif

#endif
