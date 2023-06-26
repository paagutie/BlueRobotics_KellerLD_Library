#include "KellerLD.h"
#include <iomanip> 

int main(int argc, char *argv[])
{
    int file;
    char filename[15] = {"/dev/i2c-1"};

    file = open(filename, O_RDWR);

    std::unique_ptr<KellerLD> kellerLD = std::make_unique<KellerLD>(file, LD_ADDR);

    while(kellerLD->scan() != true) {
        printf("KellerLD scan failed!\n");
        usleep(5 * 1e6);
    }
    
    kellerLD->init();

    while(true)
    {
        if(kellerLD->read_request() == 99)
            std::cout << "Error requesting read permission!" << std::endl;
        else
        {
            //The sensor needs at least 9ms to compute the internal variables
            usleep(9 * 1e3);
            if(kellerLD->read_data() != 99)
            {
                float depth = kellerLD->depth();
                float temperature = kellerLD->temperature();
                float pressure = kellerLD->pressure(KellerLD::bar);
                
                std::cout << "depth [m]: " << std::setprecision(3) << depth
                          << " temperature [°C]: " << temperature
                          << " pressure [bar]: " <<  pressure
                          << std::endl;
            }

        }
        
        usleep(0.5 * 1e6);
    }

    return 0;
}
