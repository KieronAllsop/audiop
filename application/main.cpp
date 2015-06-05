// Standard Library Includes
#include <iostream>

// Boost Includes
// None
#include <boost/program_options.hpp>

// Local Includes
#include "application/version.hpp"



int main( int argc, char* argv[] )
{
    namespace po = boost::program_options;

    po::options_description OptionsDescription( "Program Options" );
    OptionsDescription.add_options()
    ( "help", "produce help message" )
    ( "version,v", "print version string" )
    ;

    po::variables_map vm;
    po::store( po::parse_command_line( argc, argv, OptionsDescription ), vm );
    po::notify( vm );

    if ( vm.count( "help" ) )
    {
        std::cout << OptionsDescription << "\n";
        return 1;
    }

    if ( vm.count( "version" ) )
    {
        std::cout << audiop::build::identity::report() << std::endl;
        return 1;
    }

    return 0;
}
