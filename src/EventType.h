#ifndef E_MODULE_EVENT_TYPE
#define E_MODULE_EVENT_TYPE

#include <string>
#include <cstdint>

using namespace std;

namespace E_Module
{
	class EventType
	{
	public:
		EventType(string str);

		string getOrigString() const;

		uint32_t getIdentifier() const;

		bool operator == (const EventType& other) const;

		bool operator > (const EventType& other) const;

		bool operator < (const EventType& other) const;

		static const string WILD_CARD_EVENT_TYPE_STRING;
		static const uint32_t WILD_CARD_EVENT_TYPE_ID;

	private:
		uint32_t _calculateHashValue(string str) const;

		string mOrigString;
		uint32_t mIdentifier;
	};
}

#endif