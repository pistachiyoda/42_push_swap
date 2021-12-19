/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:29:39 by mai               #+#    #+#             */
/*   Updated: 2021/12/19 18:05:58 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックの内容がソート済みになっていたらtrue, なっていなかったらfalseを返す
bool	is_sorted(t_stack *stack)  // スタックが空の時セグフォしてる
{
	t_node	*node;

	node = stack->top;
	while (node->next != stack->top)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

// スタックの値から最小値の検索し、返す
int	get_min_index(t_stack *stack)
{
	int		i;
	int		min_value;
	int		min_index;
	t_node	*node;

	i = 1;
	min_index = 0;
	min_value = stack->top->value;
	node = stack->top->next;
	while (node != stack->top)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_index = i;
		}
		i++;
		node = node->next;
	}
	return (min_index);
}

// スタックの値を表示、確認用、後で消す！！！！！！！
void	print_stack(t_stack *stack)
{
	t_node	*node;
	int		len;

	len = cnt_dllist(stack);
	node = stack->top;
	if (!node)
		return ;
	printf("======start print stack======\n");
	while (len--)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n======end print stack======\n");
}

// 3つの値のうち、真ん中の値を返す
int get_med_of_3vals(int a, int b, int c)
{
    if (a < b)
        if (b < c)
            return b;
        else if (a < c)
            return c;
        else
            return a;
    else
        if (a < c)
            return a;
        else if (b < c)
            return c;
        else
            return b;
}

// 5つの値のうち、真ん中の値を返す
int *selection_sort(int cnt, int *nums)
{
	int i;
	int j;
	int k;
	int min;
	int tmp;
	int mid;

	i = 0;
	while (i < cnt)
	{
		min = nums[i]; 
		k = i;
		j = i + 1;
		while (j < cnt)
		{
			if (nums[j] < min)
			{
				min = nums[j];
				k = j;
				tmp = nums[i];
				nums[i] = nums[k];
				nums[k] = tmp;
			}
			j++;
		}
		i++;
	}
    return (nums);
}

int *sort_nums(t_stack *stack)
{
	int cnt;
	int i;
	int *nums;
	t_node *node;

	cnt = cnt_dllist(stack);
	i = 0;
	nums = (int *)malloc(cnt);
	node = stack->top;
	while (i < cnt)
	{
		nums[i] = node->value;
		node = node->next;
		i++;
	}
	return (selection_sort(cnt, nums));
}

// スタックからピボットとする値を選択する
// ピボットは中央値とする
int	choice_pivot(int *nums, int cnt)
{
	int mid;

	if ((cnt % 2) == 0)
		mid = cnt / 2;
	else
		mid = (cnt + 1) / 2;
	return (nums[mid]);
}

// スタックaの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
// 初回のみ
void	split_a_stack(t_stack *a, t_stack *b, int len)
{
	int		pivot;
	t_node	*node;
	int		*nums;

	nums = sort_nums(a);
	pivot = choice_pivot(nums, len);
	while (len)
	{
		if (pivot >= a->top->value)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
}

// スタックbの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
void	split_b_stack(t_stack *a, t_stack *b, int *sorted_len)
{
	int		pivot;
	t_node	*node;
	int		len;
	int		*nums;
	int		min_val;

	len = cnt_dllist(b);
	// スタック中の値をソート済みの配列にして返す
	nums = sort_nums(b);
	// ピボットの選択→[cnt_dlist(b) / 2]
	pivot = choice_pivot(nums, len);
	// 最小→[0]
	min_val = nums[0];
	while (len)
	{
		if (b->top->value == min_val)
		{
			push_a(a, b);
			rotate_a(a);
			*sorted_len += 1;
			nums = sort_nums(b);
			min_val = nums[0];
		}
		else if (pivot <= b->top->value)
			push_a(a, b);
		else
			rotate_b(b);
		len--;
	}
}

// スタックの内容が分割可能（７以上）ならtrue, なっていなかったらfalseを返す
bool	is_splittable(t_stack *stack)
{
	int	cnt;

	cnt = cnt_dllist(stack);
	if (cnt >= 7)
		return (true);
	return (false);
}

// スタックbの値をaの末尾に追加する
void	add_min_values(t_stack *a, t_stack *b, int b_len)
{
	while (b_len --)
	{
		push_a(a, b);
		rotate_a(a);
	}
}

int get_min_value_in_range(t_stack *stack, int len)
{
	t_node *node;
	int min;

	node = stack->top;
	min = node->value;
	while (len)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
		len --;
	}
	return (min);
}

int get_min_value(t_stack *stack)
{
	t_node *node;
	int min;

	node = stack->top->next;
	min = stack->top->value;
	while (node != stack->top)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}

// ソートされていないスタックaにある値をスタックbに移動する
// 最小値がきたときはスタックaの末尾に移動
void	push_without_sorted(t_stack *a, t_stack *b, int len, int *sorted_len)
{
	int min;
	int a_min;
	int b_min;

	min = get_min_value_in_range(a, len - *sorted_len);
	while (len > *sorted_len)
	{
		if (a->top->value == min)
		{
			rotate_a(a);
			*sorted_len += 1;
			if (!b->top)
				min = get_min_value_in_range(a, len - *sorted_len);
			else
			{
				a_min = get_min_value_in_range(a, len - *sorted_len);
				b_min = get_min_value(b);
				if (a_min < b_min)
					min = a_min;
			}
		}
		else
		{
			push_b(a, b);
			len--;
		}
	}
}
