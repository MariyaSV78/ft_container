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
# include "utils/utils.hpp"

namespace ft 
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map {
	
		public:
		// types:
			
			typedef Key 														key_type;
			typedef T 															mapped_type;
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef Compare 													key_compare;

			class value_compare: public ft::binary_function<value_type, value_type, bool> 
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:
					Compare _comp;
					value_compare(Compare c) : _comp(c) {}
					
				public:
					bool operator()(const value_type& x, const value_type& y) const 
					{ return comp(x.first, y.first);}

			};

			typedef Alloc	 													allocator_type;
			typedef typename allocator_type::reference 							reference;
			typedef typename allocator_type::const_reference 					const_reference;
			typedef typename allocator_type::pointer 							pointer;
			typedef typename allocator_type::const_pointer 						const_pointer;
	!		typedef ft::Binary_tree<value_type, key_compare>::iterator 			iterator;				 
	!		typedef ft::Binary_tree<value_type, key_compare>::const_iterator 	const_iterator;
			typedef ft::reveres_iterator<iterator>								reverse_iterator;
			typedef ft::reveres_iterator<const_iterator> 						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;
			typedef size_t 														size_type;
	// !		typedef	typename allocator_type::difference_type 					difference_type;
	// !		typedef	typename allocator_type::size_type 							size_type;

		private:
			allocator_type                           _alloc;
			Compare                                  _compare;
			Binary_search_tree<value_type, Compare>  _tree;


	//construct/copy/destroy:

	//Construct an empty map container object.
		explicit map(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc),
			_compare(compare),
			_tree(){}

	//Construct a list container, of size last-first containing value of [first, last).	
		template <class InputIterator>
			map(InputIterator first, InputIterator last, 
					const key_compare& compare = key_compare(), 
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullpt):
			_alloc(alloc),
			_compare(compare),
			_tree();
			{
				while (first != last) //this->insert(first,last) ?
				{
					_tree.insert(*first); 
					first++;
				}
			}

		map(const map& x):
			_alloc(x._alloc),
			_compare(.x_compare);
			_tree()
		{
			*this = x; // this->insert(x.begin(), x.end());
		}
		
		map& operator=(const map& x)
		{
			if (this == &x)
				return *this;
			this->clear();
			if (x.size())
				insert (x.begin(), x.end());
			_alloc = x._alloc;
			_compare = x._compare;
			return *this;
		}

		~map()
		{ this->clear();}

	// iterators:
		iterator begin()
		{ return iterator(_tree._last_node->left, _tree._last_node);}

		const_iterator begin() const
		{ return const_iterator(_tree._last_node->left, _tree._last_node);}

		iterator end()
		{ return iterator(_tree._last_node, _tree._last_node);}

		const_iterator end() const
		{ return const_iterator(_tree._last_node, _tree._last_node);}

		reverse_iterator rbegin()
		{ return reverse_iterator(this->end()); }

		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(this->end()); }

		reverse_iterator rend()
		{ return reverse_iterator(this->begin()); }


		const_reverse_iterator rend() const
		{ return const_reverse_iterator(this->begin()); }

	// capacity:
		bool		empty() const
		{ return (_tree._last_node->parent == _tree._last_node); }

		size_type 	size() const
		size_type size() const
		{ return _tree._last_node->value.first; }

		size_type 	max_size() const
		{ return _tree.max_size(); }		

	// element access:
		mapped_type& operator[](const key_type& x)
		{
			iterator tmp = this->find(x);

			if (tmp == this->end())
				this->insert(ft::make_pair(x, mapped_type()));
			tmp = this->find(x);
			return (*tmp).second;
		} 	

	// modifiers:
		pair<iterator, bool>	insert(const value_type& value) // return in key the iterator position of the inserted value + a bool: true if a new element was inserted or false if an equivalent key already exist, on value.
		{ return _tree.insertPair(value); }

		iterator 	insert(iterator position, const value_type& x);

		template <class InputIterator>
			void 	insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& x);
		void erase(iterator first, iterator last);S
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
