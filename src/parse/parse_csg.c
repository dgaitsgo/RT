/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_csg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/16 12:26:00 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	is_csg(char **tokens, int *i, t_node *field)
{
	if (accept(tokens[*i], "Union", i))
		field->csg_op = (*csg_union);
	else if (accept(tokens[*i], "Difference", i))
		field->csg_op = (*csg_difference);
	else if (accept(tokens[*i], "Intersection", i))
		field->csg_op = (*csg_intersection);
	else
		parse_error(UNEXPECTED_SYMBOL, NULL, 0);
}

void	parse_e_container(char **tokens, int *i, t_node *field, int e)
{
	expect(tokens[*i], "{", i);
	field->object = new_object(e);
	field->object->type = e;
	if (e == SPHERE)
		field->intersect = inter_sphere;
	if (e == CONE)
		field->intersect = inter_cone;
	if (e == CYLINDER)
		field->intersect = inter_cylinder;
	if (e == PLANE)
		field->intersect = inter_plane;
	parse_primitive(tokens, i, field->object, 0);
	expect(tokens[*i], "}", i);
}

void	parse_node(char **tokens, int *i, t_node *field, int max_depth)
{
	expect(tokens[*i], "{", i);
	if (check(tokens[*i], "}"))
		return ;
	if (accept(tokens[*i], "Sphere", i))
		parse_e_container(tokens, i, field, SPHERE);
	else if (accept(tokens[*i], "Cone", i))
		parse_e_container(tokens, i, field, CONE);
	else if (accept(tokens[*i], "Cylinder", i))
		parse_e_container(tokens, i, field, CYLINDER);
	else if (accept(tokens[*i], "Plane", i))
		parse_e_container(tokens, i, field, PLANE);
	else
	{
		parse_csg_container(tokens, i, field);
	}
}

void	parse_csg(char **tokens, int *i, t_node *field, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_CSG_ELEMENTS)
	{
		field->object = NULL;
		field->intersect = NULL;
		return ;
	}
	if (accept(tokens[*i], "Left", i))
	{
		if ((field->left = ft_memalloc(sizeof(t_node))) == NULL)
			parse_error(MEMORY_ERROR, tokens, i);
		parse_node(tokens, i, field->left, 0);
		expect(tokens[*i], "}", i);
	}
	if (accept(tokens[*i], "Right", i))
	{
		if ((field->right = ft_memalloc(sizeof(t_node))) == NULL)
			parse_error(MEMORY_ERROR, tokens, i);
		parse_node(tokens, i, field->right, 0);
		expect(tokens[*i], "}", i);
	}
	parse_csg(tokens, i, field, max_depth + 1);
}

void	parse_csg_container(char **tokens, int *i, t_node *field)
{
	is_csg(tokens, i, field);
	if (expect(tokens[*i], "{", i))
	{
		parse_csg(tokens, i, field, 0);
	}
	expect(tokens[*i], "}", i);
}
