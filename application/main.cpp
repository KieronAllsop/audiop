// Standard Library Includes
#include <iostream>

// Boost Includes
// None
#include <boost/program_options.hpp>

// Local Includes
#include "application/version.hpp"

namespace po = boost::program_options;

void printName()
{
    std::string yourname;
    std::cout << "Enter name: ";
    std::cin >> yourname;
    std::cout <<"\n\nHello " << yourname << std::endl;
}

int getNumber()
{
    int num;
    std::cout << "Enter a number: ";
    std:: cin >> num;
    return num;
}

int main( int argc, char* argv[] )
{
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


    int number;
    printName();
    std::cout << "Enter a number: ";
    number = 0;
    std::cin >> number;
    std::cout << "You entered " << number << std::endl;

    for( int loop = 0 ; loop < 10 ; loop++ )
    {
        std::cout << loop << std::endl;
    }



    int num1 = getNumber();
    int num2 = getNumber();

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;

    if ( number < 129 )
    {
        std::cout << "number is equal to: " << number;
    }
    else
    {
        std::cout << "invalid";
    }
    return 0;
}
