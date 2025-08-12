#include <string>
#include <iostream>
#include <thread>
#include <chrono>

int main(){
    std::string mensagem = "FSA - Fundação";
    int largura = 30;

    std::string scroll = mensagem + std::string(largura,' ');

    while (true) {
    for (size_t i = 0; i <scroll.size() - largura + 1; ++i){
        std::string window = scroll.substr(i,largura);

        std::cout << "\r" << window  << std:: flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

    std::cout <<std::endl;
    return 0;
}