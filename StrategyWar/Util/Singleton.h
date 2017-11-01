//Singleton from KwunchaLichuntsa / Singleton on GitHub.com
// https://github.com/KwunchaLichuntsa/Singleton
#pragma once

//Prevent more than one instantiation
#define SINGLETON_HPP(OBJ) friend class Util::Singleton< OBJ >; \
						   protected: \
						   OBJ() = default; \
						   virtual ~OBJ() = default;

#define SINGLETON_SPECIAL_CONSTRUCTOR(OBJ) friend class Util::Singleton< OBJ >; \
										   protected: \
										   OBJ(); \
										   virtual ~OBJ() = default;

#define SINGLETON_SPECIAL_CON_DES(OBJ) friend class Util::Singleton< OBJ >; \
						   protected: \
						   OBJ(); \
						   virtual ~OBJ();


//Helper class
namespace Util {
	class NonCopyable {
	protected:
		NonCopyable() = default;
		virtual ~NonCopyable() {};
	
	private:
		NonCopyable(const NonCopyable& rhs);
		NonCopyable operator=(NonCopyable& rhs);
		NonCopyable(NonCopyable&& other);
		NonCopyable& operator=(NonCopyable&& rhs);
	};
	
	template <typename T>
	class Singleton : NonCopyable
	{
	public:
	
		static T& getSingleton() {
			static T t;
			return t;
		}
	
		static T* getSingletonPtr() {
			return &getSingleton();
		}
	
	protected:
		explicit Singleton<T>() {};
	};
}
