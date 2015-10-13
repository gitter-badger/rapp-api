#ifndef RAPP_OBJECT_PICTURE
#define RAPP_OBJECT_PICTURE
#include "Includes.ihh"
namespace rapp {
namespace object {
/**
 * @class picture
 * @brief class which wraps around raw bytes of a picture
 * @version 2
 * @date 6-February-2015
 * @author Alex Gkiokas <a.gkiokas@ortelio.co.uk>
 */
class picture
{
public:

    /// Construct from a file-path
    picture ( const std::string filepath )
    {
        std::ifstream bytestream( filepath, 
                                  std::ios::in | std::ios::binary | std::ios::ate );
        if ( !bytestream.is_open() )
            throw std::runtime_error ( "picture: could not open bytestream for " + filepath );
        else 
            openCopy_ ( bytestream );
    }

    /// Construct using an open file stream
    picture ( std::ifstream & bytestream )
    {
        openCopy_( bytestream );
    }

    /// Copy constructor
    picture ( const picture & ) = default;

    /// Get picture as array of bytes
    std::vector<rapp::types::byte> bytearray ( ) const
    {
        return bytearray_;
    }

    /// Are pictures same ?
    bool operator== ( const picture & rhs ) const
    {
        return ( this->bytearray_ == rhs.bytearray_ );
    }

    /// Assignment operator
    picture & operator= ( const picture & ) = default;

    /// Save picture to filepath
    bool save ( const std::string filepath )
    {
        std::ofstream os ( filepath, std::ios::out | std::ofstream::binary );
        if ( os.is_open() )
        {
            std::copy( bytearray_.begin(), bytearray_.end(), 
                       std::ostreambuf_iterator<rapp::types::byte>( os ) );
            os.close();
            return true;
        }
        else
            return false;
    }

private:

    // Delete empty constructor    
    picture ( ) = delete;

    // Parse the bytestream into the bytearray
    void openCopy_ ( std::ifstream & bytestream )
    {
        bytestream.seekg( 0, std::ios_base::end);
        std::streampos fileSize = bytestream.tellg();
        bytearray_.resize( fileSize );
        bytestream.seekg( 0, std::ios_base::beg );
        bytestream.read( &bytearray_[0], fileSize );
    }

    
    std::vector<rapp::types::byte> bytearray_;
};
}
}
#endif
