/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus(1).c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:35:55 by vloureir          #+#    #+#             */
/*   Updated: 2025/04/29 16:16:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ccw test_bonus.c -L. -lft -I. libft.h

void	ft_free(void *data);
void	print_list(t_list *lst);
void	ft_iter(void *data);
void	*ft_mapi(void *data);

int	main(void)
{
    int		i;
    char	*new;
    t_list	*list;
    t_list	*mapi;  
    t_list	*node;

    i = 0;
    list = NULL;
    mapi = NULL;
    while (i < 8)
    {
        new = malloc(sizeof(char) * 1 + 1);
        new[0] = 'a' + i;
        new[1] = '\0';
        node = ft_lstnew(new);
        ft_lstadd_front(&list, node);
        i++;
    }
    printf("\n");
    printf("size: %d\n", ft_lstsize(list));
    printf("\nadd_front: ");
    print_list(list);
    printf("last:%s\n", (char *)(ft_lstlast(list))->content);
    ft_lstclear(&list, ft_free);
    i = 0;
    list = NULL;
    while (i < 8)
    {
        new = malloc(sizeof(char) * 1 + 1);
        new[0] = 'a' + i;
        new[1] = '\0';
        node = ft_lstnew(new);
        ft_lstadd_back(&list, node);
        i++;
    }
    printf("\nadd_back: ");
    print_list(list);
    printf("last:%s\n", (char *)(ft_lstlast(list))->content);
    ft_lstiter(list, ft_iter);
    printf("\niter: ");
    print_list(list);
    mapi = ft_lstmap(list, ft_mapi, ft_free);
    printf("\nmapi:");
    printf("\nold: ");
    print_list(list);
    printf("new: ");
    print_list(mapi);
    ft_lstclear(&list, ft_free);
    ft_lstclear(&mapi, ft_free);
    printf("\n");
    
    printf("--- NULL test ---\n\n");
    node = ft_lstnew("NULL");
    ft_lstadd_back(NULL, node);
    printf("ft_lstadd_back   ok");
    ft_lstadd_back(&node, NULL);
    printf(" ok");
    ft_lstadd_back(NULL, NULL);
    printf(" ok\n");
    ft_lstadd_front(NULL, NULL);
    printf("ft_lstadd_front  ok");
    ft_lstadd_front(NULL, node);
    printf(" ok");
    ft_lstadd_front(&node, NULL);
    printf(" ok\n");
    ft_lstdelone(node, NULL);
    printf("ft_lstdelone     ok");
    ft_lstdelone(NULL, NULL);
    printf(" ok\n");
    ft_lstclear(NULL, NULL);
    printf("ft_lstclear      ok");
    ft_lstclear(&node, NULL);
    printf(" ok\n");
    ft_lstlast(NULL);
    printf("ft_lstlast       ok\n");
    ft_lstsize(NULL);
    printf("ft_lstsize       ok\n");
    ft_lstiter(NULL, NULL);
    printf("ft_lstiter       ok\n");
    mapi = ft_lstmap(NULL, NULL, NULL);
    printf("ft_lstmap        ok\n");
    free(node);
}

void	ft_iter(void *data)
{
    int		i;
    char	*new;
    
    new = (char *)data;
    i = -1;
    while (new[++i])
        new[i] = new[i] + 1;
}

void	*ft_mapi(void *data)
{
    char	*new;
    
    new = malloc(sizeof(char) * 1 + 1);
    new[0] = ((char *)data)[0] + 1;
    new[1] = '\0';
    return (new);
}


void	ft_free(void *data)
{
    free(data);
}

void	print_list(t_list *lst)
{
    t_list	*ptr;

    ptr = lst;
    while (ptr)
    {
        printf("%s -> ", (char *)ptr->content);
        ptr = ptr->next;
    }
    printf("\n");
}