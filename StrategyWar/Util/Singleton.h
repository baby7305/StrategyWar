//Singleton from Ogre engine
#pragma once
#ifdef _MSC_VER
	//#pragma warning (push)
	//#pragma warning ( disable: 4661)
#endif

#define SINGLEON_CPP(OBJ) template<> OBJ* Ogre::Singleton<OBJ>::msSingleton = 0; 

namespace Util {

	template <typename T>
	class Singleton
	{
	private:
		Singleton(const Singleton<T> &);
		Singleton& operator=(const Singleton<T> &);

	protected:
		static T* msSingleton;

	public:
		Singleton() {
			assert(!msSingleton);
			#if defined( _MSC_VER ) && _MSC_VER < 1200   
			int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
			msSingleton = (T*)((int)this + offset);
			#else
			msSingleton = static_cast< T* >(this);
			#endif
		}

		~Singleton(){
			assert(msSingleton);
			msSingleton = nullptr;
		}
		/// Get the singleton instance
		static T& getSingleton()
		{
			assert(msSingleton);
			return (*msSingleton);
		}

		static T* getSingletonPtr()
		{
			return msSingleton;
		}
	};
}

#ifdef _MSC_VER
	//#pragma warning (pop)
#endif
