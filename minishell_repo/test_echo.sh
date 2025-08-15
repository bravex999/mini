#!/bin/bash

# --- Script de pruebas para TU minishell ---
# Se comunica con tu programa pasándole texto, sin flags raros.

MINISHELL="./minishell" # Asegúrate de que tu ejecutable se llama así
total_tests=0
passed_tests=0

# Función de prueba
# $1: Descripción
# $2: La línea de comando a probar
test_case() {
    ((total_tests++))
    description="$1"
    command_line="$2"

    # Salida esperada (la de Bash)
    expected_output=$(bash -c "$command_line")

    # Salida real (la de tu minishell)
    # Le pasamos el comando a través de una tubería, directo a su stdin.
    actual_output=$(echo "$command_line" | $MINISHELL)

    # Comparamos
    if [ "$actual_output" == "$expected_output" ]; then
        printf "[OK]   - %s\n" "$description"
        ((passed_tests++))
    else
        printf "[FAIL] - %s\n" "$description"
        printf "         ESPERADO: >%s<\n" "$expected_output"
        printf "         OBTENIDO: >%s<\n" "$actual_output"
    fi
}

# --- Suite de Pruebas ---
echo "--- Ejecutando tests para 'echo' ---"

# Básicos
test_case "Una palabra" "echo hola"
test_case "Múltiples palabras" "echo hola mundo"
test_case "Echo solo con salto de línea" "echo"

# Pruebas de -n
test_case "-n simple" "echo -n hola"
test_case "-n con múltiples palabras" "echo -n hola mundo"
test_case "-nn" "echo -nn hola"
test_case "-nnnnn" "echo -nnnnn hola"
test_case "-n múltiples veces" "echo -n -n hola"
test_case "-n solo" "echo -n"
test_case "-n como texto al final" "echo hola -n test"

# Pruebas de comillas (tu parser debe crear un solo token)
test_case "Comillas dobles" 'echo "hola mundo"'
test_case "Comillas simples" "echo 'hola mundo'"
test_case "Comillas vacías" 'echo ""'
test_case "Combinación de argumentos" 'echo hola "mundo" '\''test'\'''

# Pruebas con -n y comillas
test_case "-n con comillas dobles" 'echo -n "hola mundo"'
test_case "-n con comillas simples" "echo -n 'hola mundo'"
test_case "-n seguido de comillas" 'echo -n "hola" "mundo"'

# Casos límite
test_case "Múltiples espacios (el parser debe reducirlos)" "echo hola        mundo"
test_case "Comillas como parte de una palabra" 'echo hola"mundo"'


# --- Resumen ---
echo "-------------------------------------"
echo "Resultado: $passed_tests / $total_tests pruebas correctas."
echo "-------------------------------------"

if [ "$passed_tests" -ne "$total_tests" ]; then
    exit 1
fi
