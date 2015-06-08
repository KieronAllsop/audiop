// Standard Library Includes
#include <iostream>

// Boost Includes
#include <boost/program_options.hpp>

// Thirdparty Includes
#include "spdlog/spdlog.h"

// Local Includes
#include "application/version.hpp"

void logger()
{
    auto ConsoleLog = spdlog::stdout_logger_mt( "console" );
    ConsoleLog->info( audiop::build::identity::product_version() );

    auto FileLogger = spdlog::rotating_logger_mt( "main", "audiop", 512, 9 );
    FileLogger->info( audiop::build::identity::report() );
}


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

    logger();

    return 0;
}
