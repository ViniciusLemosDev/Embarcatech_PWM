# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializa pico_sdk
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o SDK do Pico
include(pico_sdk_import.cmake)

project(Embarcatech_PWM C CXX ASM)

# Inicializa o SDK do Pico
pico_sdk_init()

# Adiciona o executável
add_executable(Embarcatech_PWM Embarcatech_PWM.c)

pico_set_program_name(Embarcatech_PWM "Embacatech_PWM")
pico_set_program_version(Embarcatech_PWM "0.1")

# Habilita saída via UART e USB
pico_enable_stdio_uart(Embarcatech_PWM 1)
pico_enable_stdio_usb(Embarcatech_PWM 1)

# Adiciona bibliotecas necessárias
target_link_libraries(Embarcatech_PWM
    pico_stdlib
    hardware_pwm  # 🔥 Adiciona a biblioteca de PWM
)

# Adiciona os diretórios de include
target_include_directories(Embarcatech_PWM PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gera arquivos extras (como UF2)
pico_add_extra_outputs(Embarcatech_PWM)
