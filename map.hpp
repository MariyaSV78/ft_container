/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:55:31 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/07 00:55:34 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <iterator>
# include "utils/mapIterator.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/pair.hpp"
# include "utils/AVLTree.hpp"

namespace ft 
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map {
	
		public:
		// types:
			
			typedef Key 														key_type;
			typedef T 															mapped_type;
			typedef pair<const key_type, mapped_type>							value_type;
			typedef Compare 													key_compare;
			typedef Alloc	 													allocator_type;
			typedef typename allocator_type::reference 							reference;
			typedef typename allocator_type::const_reference 					const_reference;
			typedef typename allocator_type::pointer 							pointer;
			typedef typename allocator_type::const_pointer 						const_pointer;
			typedef ft::Binary_tree<value_type, key_compare>::iterator 			iterator;				 
			typedef ft::Binary_tree<value_type, key_compare>::const_iterator 	const_iterator;
			typedef std::reverse_iterator<iterator>								reverse_iterator;
			typedef std::reverse_iterator<const_iterator> 						const_reverse_iterator;
			typedef	typename allocator_type::difference_type 					difference_type;
			typedef	typename allocator_type::size_type 							size_type;

		private:
			allocator_type                           _alloc;
			Compare                                  _comp;
			Binary_search_tree<value_type, Compare>  _tree;


		public:
		class value_compare: public ft::binary_function<value_type,value_type,bool> 
		{
			friend class map;
			protected:
				Compare _comp;
				value_compare(Compare c) : _comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const 
				{ return comp(x.first, y.first);}
		};
	//construct/copy/destroy:
		explicit map(const key_compare& compar = key_compare(), const Allocator& = Allocator()):
			_alloc(alloc),
			_compar(compar),
			_tree();{}
		
		template <class InputIterator>
			map(InputIterator first, InputIterator last, 
					const key_compare& compar = key_compare(), 
					const allocator_type& alloc = allocator_type(),
					ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullpt):
			_alloc(alloc),
			_compar(compar),
			_tree();
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}

		map(const map<Key,T,Compare,Allocator>& x):
			_alloc(x._alloc),
			_compar(.x_compar);
			_tree()
		{
			*this = x;
		}
		
		map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x)
		{
			if (this == &x)
				return *this;
			_tree.clear();
			if (x.size())
				insert (x.begin(), x.end());
			_alloc = x._alloc;
			_compar = x._compar;
			return *this;
		}

		~map();

	// iterators:
		iterator begin()
		{
			return (iterator)
		}
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
	// capacity:
		bool		empty() const;
		size_type 	size() const;
		size_type 	max_size() const;

	// element access:
		T& operator[](const key_type& x);
	// modifiers:
		pair<iterator, bool>	insert(const value_type& x);
		iterator 	insert(iterator position, const value_type& x);
		template <class InputIterator>
			void 	insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& x);
		void erase(iterator first, iterator last);
		void swap(map<Key,T,Compare,Allocator>&);
		void clear();
	// observers:
		key_compare key_comp() const;
		value_compare value_comp() const;
	
	// map operations:
		iterator 	find(const key_type& x);
		const_iterator find(const key_type& x) const;
		size_type 	count(const key_type& x) const;
		iterator 	lower_bound(const key_type& x);
		const_iterator lower_bound(const key_type& x) const;
		iterator 	upper_bound(const key_type& x);
		const_iterator upper_bound(const key_type& x) const;
		
		pair<iterator,iterator>
			equal_range(const key_type& x);

		pair<const_iterator,const_iterator>
			equal_range(const key_type& x) const;
	};
		template <class Key, class T, class Compare, class Allocator>
			bool operator==(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
			bool operator< (const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
			bool operator!=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
			bool operator> (const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
			bool operator>=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
			bool operator<=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y);
	// specialized algorithms:
		template <class Key, class T, class Compare, class Allocator>
			void swap(map<Key,T,Compare,Allocator>& x,
					  map<Key,T,Compare,Allocator>& y);
	}
#endif
