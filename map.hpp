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


# include "utils/reverseIterator.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/binary_search_tree.hpp"
//# include "utils/binary_search_tree_iter.hpp"
# include "utils/utils.hpp"
# include "utils/enable_if.hpp"

namespace ft 
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
	
		public:
		// types:
			
			typedef Key 														key_type;
			typedef T 															mapped_type;
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef Compare 													key_compare;

			class value_compare:ft::binary_function<value_type, value_type, bool> 
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:
					key_compare		_compar;
					value_compare(key_compare c) : _compar(c) {}

				public:
					bool operator()(const value_type& x, const value_type& y) const 
					{ return _compar(x.first, y.first);}
			};

			typedef Alloc	 													allocator_type;
			typedef typename allocator_type::reference 							reference;
			typedef typename allocator_type::const_reference 					const_reference;
			typedef typename allocator_type::pointer 							pointer;
			typedef typename allocator_type::const_pointer 						const_pointer;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator 			iterator;				 
			typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator 	const_iterator;
			typedef typename ft::reveres_iterator<iterator>								reverse_iterator;
			typedef typename ft::reveres_iterator<const_iterator> 						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;
			typedef size_t 														size_type;
	// !		typedef	typename allocator_type::difference_type 					difference_type;
	// !		typedef	typename allocator_type::size_type 							size_type;

		
		private:
			allocator_type                          		 _alloc;
			key_compare                                 	 _compare;
			Binary_search_tree<value_type, key_compare> 	 _bst;

	public:
	//construct/copy/destroy:

	//Construct an empty map container object.
		explicit map(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc),
			_compare(compare),
			_bst(){} //?  _tree(tree_type(comp, alloc))

	//Construct a list container, of size last-first containing value of [first, last).	
		template <class InputIterator>
			map(InputIterator first, InputIterator last, 
					const key_compare& compare = key_compare(), 
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = my_nullptr):
				_alloc(alloc),
				_compare(compare),
				_bst()
				{
					this->insert(first,last);
					// while (first != last) // ?
					// {
					// 	_bst.insert(*first); 
					// 	first++;
					// }
				}

		map(const map& x):
			_alloc(x._alloc),
			_compare(x._compare),
			_bst()
			{
				this->insert(x.begin(), x.end()); // *this = x;
			}
		
		map& operator=(const map& x)
		{
			if (this == &x)
				return *this;
			this->clear();
			// if (x.size())
			// 	insert (x.begin(), x.end());
			// _alloc = x._alloc;
			// _compare = x._compare;
			this->insert(x.begin(), x.end());
			return *this;
		}

			// {
			// 	if (&x == this)
			// 		return (*this);
			// 	this->clear();
			// 	this->insert(x.begin(), x.end());
			// 	return (*this);
			// }

		~map()
		{ this->clear();}

		allocator_type get_allocator() const
		{
			return _alloc;
		}


	// iterators:
		iterator begin()
		{ return iterator(_bst._last_node->left, _bst._last_node);} // ?? _bst.begin()?

		const_iterator begin() const
		{ return const_iterator(_bst._last_node->left, _bst._last_node);}

		iterator end()
		{ return iterator(_bst._last_node, _bst._last_node);}

		const_iterator end() const
		{ return const_iterator(_bst._last_node, _bst._last_node);}

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
		{ return (_bst._last_node->parent == _bst._last_node); }

		size_type size() const
		{ return _bst._last_node->value.first; }

		size_type 	max_size() const
		{ return _bst.max_size(); }		

	// element access:
		mapped_type& operator[](const key_type& key)
		{
			iterator tmp = this->find(key);

			if (tmp == this->end())
				this->insert(ft::make_pair(key, mapped_type())); //???? insert new element?
			tmp = this->find(key);
			return (*tmp).second; //tmp->second
		} 	

	// modifiers:
		pair<iterator, bool>	insert(const value_type& value) // return in key the iterator position of the inserted value + a bool: true if a new element was inserted or false if an equivalent key already exist, on value.
		{ return _bst.insertPair(value); }

		iterator 	insert(iterator position, const value_type& value)
		{
			(void)position;
			return _bst.insertPair(value).first;
		}

		template <class InputIterator>
			void 	insert(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = my_nullptr)
		{
				//bool is_valid;
				// if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
				// 	throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
				difference_type n = ft::distance(first, last);
				while (n--)
					insert(*(first++));
		}

		void erase(iterator position) // Remove the element in the container at the iterator position.
		{ this->erase((*position).first); }

		size_type erase(const key_type& key) //  Remove the element in the container that has like key "x".
		{
			if (this->find(key) == this->end())
				return (0);
			_bst.removeByKey(ft::make_pair(key, mapped_type()));
			return (1);
		}

		void erase(iterator first, iterator last) // Remove a range [first, last) element
		{
			while (first != last)
				this->erase((*(first++)).first);
		}

		void swap(map& x)
		{ _bst.swap(x._bst); }

		void clear()
		{ this->erase(this->begin(), this->end()); }


	// observers:
		key_compare key_comp() const
		{ return key_compare(); }

		value_compare value_comp() const
		{ return value_compare(key_compare()); }		
	
	// map operations:
		iterator 	find(const key_type& key)  // return an iterator pointing to the pair with "key'. 
		{ return iterator(_bst.searchByKey(ft::make_pair(key, mapped_type())), _bst._last_node); }

		const_iterator find(const key_type& key) const
		{ return const_iterator(_bst.searchByKey(ft::make_pair(key, mapped_type()), _bst._last_node)); }

		size_type 	count(const key_type& key) const // return 1 if the map have an element with key, 0 otherwise.
		{
			const_iterator begin = this->begin();
			const_iterator end = this->end();

			while (begin != end)
				if ((*(begin++)).first == key)
					return (1);
			return (0);
		}

		iterator 	lower_bound(const key_type& key)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (_comp((*begin).first, key) == false)
					break;
				begin++;
			}
			return (begin);
		}
		
		const_iterator lower_bound(const key_type& key) const
		{ return const_iterator(this->lower_bound(key)); }

		iterator 	upper_bound(const key_type& key)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (_compare(key, (*begin).first)) 
					break;
				begin++;
			}
			return (begin);
		}

		const_iterator upper_bound(const key_type& key) const
		{return const_iterator(this->upper_bound(key));}
		
		ft::pair<iterator,iterator> equal_range(const key_type& key) // return interval like of pair: first iterator pointing to the lower bound of "key" and the second - to the upper.
		{ return ft::make_pair(this->lower_bound(key), this->upper_bound(key)); }
		
		ft::pair<const_iterator,const_iterator> equal_range(const key_type& key) const
		{ return ft::make_pair(this->lower_bound(key), this->upper_bound(key)); }



		// //template<class Key, class T, class Compare, class Alloc> 
		// 	friend bool operator==(const map<Key, T, Compare, Alloc>& x,
		// 							const map<Key, T, Compare, Alloc>& y);

		// //template<class Key, class T, class Compare, class Alloc>
		// 	friend bool operator<(const map<Key, T, Compare, Alloc> & x,
		// 						  const map<Key, T, Compare, Alloc>& y);

	};
		
		template <class Key, class T, class Compare, class Allocator>
			bool operator==(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return x._bst == y._bst ;}

		template <class Key, class T, class Compare, class Allocator>
			bool operator< (const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return x._bst < y._bst; }

		template <class Key, class T, class Compare, class Allocator>
			bool operator!=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return !(x == y) ;}
			
		template <class Key, class T, class Compare, class Allocator>
			bool operator> (const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return y < x; }

		template <class Key, class T, class Compare, class Allocator>
			bool operator>=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return !(x < y);}

		template <class Key, class T, class Compare, class Allocator>
			bool operator<=(const map<Key,T,Compare,Allocator>& x,
							const map<Key,T,Compare,Allocator>& y)
			{return !(x > y);}

	// specialized algorithms:
		template <class Key, class T, class Compare, class Allocator>
			void swap(map<Key,T,Compare,Allocator>& x,
					  map<Key,T,Compare,Allocator>& y)
			{return x.swap(y);}
	}
#endif
