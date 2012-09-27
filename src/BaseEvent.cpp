#include "BaseEvent.h"

#include <strstream>

using namespace std;

namespace E_Module
{
	BaseEvent::BaseEvent(const clock_t time_stamp)
		: mTimeStamp(time_stamp) {}

	void BaseEvent::serialize(OUT IStream& stream) const
	{
		stream << (byte8)mTimeStamp;

		onSerialize(stream);
	}

	void BaseEvent::deserialize(IN IStream& stream)
	{
		stream >> (byte8&)mTimeStamp;

		onDeserialize(stream);
	}

	string BaseEvent::toString() const
	{
		strstream ss;
		string str;
		
		ss << "[" << mTimeStamp << "] " << onToString();
		ss >> str;
		
		return str;
	}

	clock_t BaseEvent::getTimeStamp() const
	{
		return mTimeStamp;
	}

	BaseEvent::~BaseEvent() {}
}