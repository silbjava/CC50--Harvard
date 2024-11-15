from cs50 import get_int

def main():
    height = get_int("Digite a altura da pirâmide:\n")

    while (height < 1 or height > 8):
        print("Tamanho inválido! Por favor, insira um número entre 1 e 8.\n")
        height = get_int("Digite a altura da pirâmide:\n")

    for i in range(height):
        # Espaços
        print(" " * (height - i - 1), end="")
        # Hashtags
        print("#" * (i + 1))

if __name__ == "__main__":
    main()
