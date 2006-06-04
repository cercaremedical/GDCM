#include "gdcmOStream.h"
#include "gdcmByteSwap.txx"

#include <assert.h>

namespace gdcm
{

OStream& OFStream::Write(const char* s, std::streamsize n )
{
  // Following operation is nice for debuging but is way to extensive and
  // appear really high in the top ten expensive operation
  if(s) { assert( memset(s,0,n) ); }
  assert( !(!InternalStream) );
  assert( !InternalStream.eof() );
  //std::cout << InternalStream.tellg() << std::endl;
  if( !InternalStream.write(s,n) )
    {
    if( !(InternalStream.eof()))
      {
      std::cerr << "Problem reading: " << n << " bytes" << std::endl;
      assert(0);
      }
    }
  return *this; 
}

} // end namespace gdcm

