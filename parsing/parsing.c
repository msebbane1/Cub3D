/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:22:54 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/07 14:07:16 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * un paramètre (texture/couleur) est défini 2 fois
 * un paramètre n'a pas été décrit ou est décrit après la map
 * fichier de texture existe pas
 * fichier de texture qui est un dossier
 * fichier de texture qui finit pas par .xpm
 * couleur contient pas 3 nombres
 * que des nombres pour les couleurs (is digit)
 * un nombre est plus petit que 0 ou plus grand que 255
 * un paramètre est mal décrit (exemple: la ligne du nord commence par NOO et pas NO)
 * mauvais caractère dans la map
 * espace pas entouré par des murs ou par un autre espace
 * trop de positions de départ
 * aucune position de départ
 * map pas entouré de mur
 * Taille de l'ecran
 * Textures mur face = NO = nord SO = sud EA = est WE = ouest
 * F = couleur du sol
 **/