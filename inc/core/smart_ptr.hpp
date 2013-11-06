#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

namespace zsys
{
	template<typename T>
	class smart_pol
	{
		public:
			smart_pol(){}
			virtual ~smart_pol(){}

			virtual void assign( T * source, T * destination ) = 0;
			virtual void copy( T * source, T * destination ) = 0;
			virtual void destroy( T * ptr ) = 0;
	};

	template<typename T>
	class owner_pol
	{
		public:
			owner_pol(){}

			void assign( T * source, T * destination )
			{
				destination = source;
				source = nullptr;
			}
			void copy( T * source, T * destination )
			{
				assign(source, destination);
			}
			void destroy( T * ptr )
			{
				if (ptr)
					delete ptr, ptr = nullptr;
			}
	};

	template<typename T>
	class shared_pol
	{
		public:
			static count;

			shared_pol(){}

			void inc(T *p)
			{
				stack.push_back(p);
			}
			void assign( T * source, T * destination )
			{
				destination = source;
			}
			void copy( T * source, T * destination )
			{
				assign(source, destination);
			}
			void destroy( T * ptr )
			{
				if (ptr)
					delete ptr, ptr = nullptr;
			}
	};
	template<typename T, typename Pol=owner_pol<T>>
	class smart_ptr
	{
		friend class smart_ptr<T>;
		Pol 			m_pol;
		public:
			/** Default constructor */
			smart_ptr(const T *p = nullptr) : m_ptr(p){}

			/** Default destructor */
			virtual ~smart_ptr() {}

			/** Copy constructor
			 *  \param other Object to copy from
			 */
			smart_ptr(const smart_ptr& other) { m_ptr(other.m_ptr); }

			/** Assignment operator
			 *  \param other Object to assign from
			 *  \return A reference to this
			 */
			smart_ptr& operator=(const smart_ptr& other) { m_ptr = other.m_ptr; return *this; }

			void 		check(){ assert(m_ptr && "Invalid Pointer"); }

			T * 		get(){ check(); return m_ptr; }
			const T * 	get() const{ check(); return m_ptr; }
			Pol 		policy(){ return m_pol; }
		protected:
		private:
	};
};

#endif // SMART_PTR_HPP
