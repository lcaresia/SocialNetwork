namespace boost {
	namespace algorithm {
		template<typename OutputIteratorT, typename Range1T, typename Range2T>
		OutputIteratorT
			replace_range_copy(OutputIteratorT, const Range1T &,
				const iterator_range< typename range_const_iterator< Range1T >::type > &,
				const Range2T &);
		template<typename SequenceT, typename RangeT>
		SequenceT replace_range_copy(const SequenceT &,
			const iterator_range< typename range_const_iterator< SequenceT >::type > &,
			const RangeT &);
		template<typename SequenceT, typename RangeT>
		void replace_range(SequenceT &,
			const iterator_range< typename range_iterator< SequenceT >::type > &,
			const RangeT &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			replace_first_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT replace_first_copy(const SequenceT &, const Range1T &,
			const Range2T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		void replace_first(SequenceT &, const Range1T &, const Range2T &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			ireplace_first_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &,
				const std::locale & = std::locale());
		template<typename SequenceT, typename Range2T, typename Range1T>
		SequenceT ireplace_first_copy(const SequenceT &, const Range2T &,
			const Range1T &,
			const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		void ireplace_first(SequenceT &, const Range1T &, const Range2T &,
			const std::locale & = std::locale());
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			replace_last_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT replace_last_copy(const SequenceT &, const Range1T &,
			const Range2T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		void replace_last(SequenceT &, const Range1T &, const Range2T &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			ireplace_last_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &,
				const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT ireplace_last_copy(const SequenceT &, const Range1T &,
			const Range2T &,
			const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		void ireplace_last(SequenceT &, const Range1T &, const Range2T &,
			const std::locale & = std::locale());
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			replace_nth_copy(OutputIteratorT, const Range1T &, const Range2T &, int,
				const Range3T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT replace_nth_copy(const SequenceT &, const Range1T &, int,
			const Range2T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		void replace_nth(SequenceT &, const Range1T &, int, const Range2T &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			ireplace_nth_copy(OutputIteratorT, const Range1T &, const Range2T &,
				int, const Range3T &,
				const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT ireplace_nth_copy(const SequenceT &, const Range1T &, int,
			const Range2T &,
			const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		void ireplace_nth(SequenceT &, const Range1T &, int, const Range2T &,
			const std::locale & = std::locale());
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			replace_all_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT replace_all_copy(const SequenceT &, const Range1T &,
			const Range2T &);
		template<typename SequenceT, typename Range1T, typename Range2T>
		void replace_all(SequenceT &, const Range1T &, const Range2T &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T,
			typename Range3T>
			OutputIteratorT
			ireplace_all_copy(OutputIteratorT, const Range1T &, const Range2T &,
				const Range3T &, const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		SequenceT ireplace_all_copy(const SequenceT &, const Range1T &,
			const Range2T &,
			const std::locale & = std::locale());
		template<typename SequenceT, typename Range1T, typename Range2T>
		void ireplace_all(SequenceT &, const Range1T &, const Range2T &,
			const std::locale & = std::locale());
		template<typename OutputIteratorT, typename Range1T, typename Range2T>
		OutputIteratorT
			replace_head_copy(OutputIteratorT, const Range1T &, int,
				const Range2T &);
		template<typename SequenceT, typename RangeT>
		SequenceT replace_head_copy(const SequenceT &, int, const RangeT &);
		template<typename SequenceT, typename RangeT>
		void replace_head(SequenceT &, int, const RangeT &);
		template<typename OutputIteratorT, typename Range1T, typename Range2T>
		OutputIteratorT
			replace_tail_copy(OutputIteratorT, const Range1T &, int,
				const Range2T &);
		template<typename SequenceT, typename RangeT>
		SequenceT replace_tail_copy(const SequenceT &, int, const RangeT &);
		template<typename SequenceT, typename RangeT>
		void replace_tail(SequenceT &, int, const RangeT &);
	}
}