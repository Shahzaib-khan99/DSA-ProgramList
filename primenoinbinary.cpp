#include <iostream>
#include <fstream>

    int main()
          {
          int n;
     	std::cout << "Enter how many prime numbers you want ";
        std::cin >> n;

    std::ofstream file("primes.bin", std::ios::binary);

    int count = 0;
    int num = 2;

    while (count < n)
    {
        bool prime = true;

        for (int i = 2; i < num; i++)
          {
            if (num % i == 0)
            {
                prime = false;
                break;
            }
          }
        if (prime)
        
          {
            std::cout << num << " ";
            file.write((char*)&num, sizeof(num));  
            count++;
          }

        num++;
    }

    file.close();

    std::cout << "Prime numbers stored in file  primes.bin" << std::endl;

    return 0;
}