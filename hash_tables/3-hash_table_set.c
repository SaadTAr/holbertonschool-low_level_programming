#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_node - update value if key exists
 */
int update_node(hash_node_t *node, const char *key, const char *value)
{
	char *val;

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			val = strdup(value);
			if (!val)
				return (0);
			free(node->value);
			node->value = val;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

/**
 * create_node - create new node
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	return (node);
}

/**
 * hash_table_set - adds element
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (update_node(ht->array[index], key, value))
		return (1);

	node = create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
