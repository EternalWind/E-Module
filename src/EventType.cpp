#include "EventType.h"

#include <memory>
#include <strstream>

namespace E_Module
{
	const string EventType::WILD_CARD_EVENT_TYPE_STRING = "wild_card_event";
	const uint32_t EventType::WILD_CARD_EVENT_TYPE_ID = 0;

	EventType::EventType(string str)
		: mOrigString(str),
		  mIdentifier(_calculateHashValue(str)) {}

	string EventType::getOrigString() const
	{
		return mOrigString;
	}

	uint32_t EventType::getIdentifier() const
	{
		return mIdentifier;
	}

	bool EventType::operator == (const EventType& other) const
	{
		return mIdentifier == other.mIdentifier;
	}

	bool EventType::operator != (const EventType& other) const
	{
		return mIdentifier != other.mIdentifier;
	}

	bool EventType::operator < (const EventType& other) const
	{
		return mIdentifier < other.mIdentifier;
	}

	bool EventType::operator > (const EventType& other) const
	{
		return mIdentifier > other.mIdentifier;
	}

	uint32_t EventType::_calculateHashValue(string str) const
	{
		// Check for wild card event type.
		if (str == WILD_CARD_EVENT_TYPE_STRING)
		{
			return WILD_CARD_EVENT_TYPE_ID;
		}

		// DJB hashing which is much faster than Adler-32 checksum introduced in the book.
		unsigned int hash = 5381;
		const char* ch_ptr = str.c_str();
		
		while (*ch_ptr)
		{
			hash += (hash << 5) + (*ch_ptr++);
		}

		return (hash & 0x7FFFFFFF);
	}

	void EventType::serialize(OUT IStream& stream) const
	{
		stream << (byte4)mIdentifier << (byte4)mOrigString.size();
		stream.write((const byte*)mOrigString.c_str(), (byte4)mOrigString.size());
	}

	void EventType::deserialize(IN IStream& stream)
	{
		byte4 size = 0;
		shared_ptr<byte> buffer;

		stream >> (byte4&)mIdentifier >> size;

		buffer.reset(new byte[size]);
		stream.read(buffer.get(), size);

		mOrigString = string((const char*)buffer.get(), size);
	}

	string EventType::toString() const
	{
		strstream ss;
		string str;

		ss << "Event type: " << mOrigString << "(" << mIdentifier << ")";
		ss >> str;

		return str;
	}
}