#ifndef E_MODULE_SINGLETON_H
#define E_MODULE_SINGLETON_H

namespace E_Module
{
	template <typename T>
	class Singleton
	{
	public:
		static T& get()
		{
			static T instance;

			return instance;
		}

		virtual ~Singleton() = 0;
	};
}

#endif