#ifndef E_MODULE_INTERFACE_SERIALIZABLE
#define E_MODULE_INTERFACE_SERIALIZABLE

#include "Definitions.h"
#include "IStream.h"

#include <string>

using namespace std;

namespace E_Module
{
	/**
	  * An interface for all the serializable classes.
	  */
	interface E_MODULE ISerializable
	{
	public:
		/**
		  * Serializes this object.
		  * @param stream The output stream.
		  */
		virtual void serialize(OUT IStream& stream) const = 0;

		/**
		  * Deserializes an object from a given stream.
		  * @param stream The input stream.
		  */
		virtual void deserialize(IN IStream& stream) = 0;

		/**
		  * Converts this object to a string.
		  * @returns The output string.
		  */
		virtual string toString() const = 0;

		virtual ~ISerializable() = 0 {}
	};
}

#endif