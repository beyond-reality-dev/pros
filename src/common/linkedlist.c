/*
 * \file linkedlist.c
 *
 * \brief linked list implementation for internal use
 *
 * This file defines a linked list implementation that operates on the FreeRTOS
 * heap, and is able to generically store function pointers and data
 *
 * \copyright (c) 2017, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "common/linkedlist.h"

#include <stddef.h>  // NULL

#include "kapi.h"

ll_node_s_t* linked_list_init_func_node(generic_fn_t func) {
	ll_node_s_t* node = (ll_node_s_t*)kmalloc(sizeof *node);
	node->payload.func = func;
	node->next = NULL;

	return node;
}

ll_node_s_t* linked_list_init_data_node(void* data) {
	ll_node_s_t* node = (ll_node_s_t*)kmalloc(sizeof *node);
	node->payload.data = data;
	node->next = NULL;

	return node;
}

linked_list_s_t* linked_list_init() {
	linked_list_s_t* list = (linked_list_s_t*)kmalloc(sizeof *list);
	list->head = NULL;

	return list;
}

void linked_list_prepend_func(linked_list_s_t* list, generic_fn_t func) {
	if (list == NULL) list = linked_list_init();

	ll_node_s_t* n = linked_list_init_func_node(func);

	n->next = list->head;
	list->head = n;
}

void linked_list_prepend_data(linked_list_s_t* list, void* data) {
	if (list == NULL) list = linked_list_init();

	ll_node_s_t* n = linked_list_init_data_node(data);

	n->next = list->head;
	list->head = n;
}

void linked_list_append_func(linked_list_s_t* list, generic_fn_t func) {
	if (list == NULL) list = linked_list_init();

	ll_node_s_t* n = linked_list_init_func_node(func);

	if (list->head == NULL) {
		list->head = n;
		return;
	}

	ll_node_s_t* it = list->head;
	while (it->next != NULL) it = it->next;

	it->next = n;
}

void linked_list_append_data(linked_list_s_t* list, void* data) {
	if (list == NULL) list = linked_list_init();

	ll_node_s_t* n = linked_list_init_data_node(data);

	if (list->head == NULL) {
		list->head = n;
		return;
	}

	ll_node_s_t* it = list->head;
	while (it->next != NULL) it = it->next;

	it->next = n;
}

void linked_list_foreach(linked_list_s_t* list, linked_list_foreach_fn_t cb, void* extra_data) {
	if (list == NULL || list->head == NULL) return;

	ll_node_s_t* it = list->head;
	while (it != NULL) {
		cb(it, extra_data);
		it = it->next;
	}
}