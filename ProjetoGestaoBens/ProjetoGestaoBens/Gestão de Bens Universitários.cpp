#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // Para utilizar a função system()

using namespace std;

// Definição da estrutura para armazenar os dados dos bens
struct Bem {
    string nome;
    string categoria;
    string dataAquisicao;
    float peso;
    string endereco; // Apenas para imóveis
};

// Função para ler os registros dos bens de um arquivo
vector<Bem> lerRegistros() {
    vector<Bem> bens;
    ifstream arquivo("bens.txt");
    if (arquivo.is_open()) {
        Bem bem;
        while (arquivo >> bem.nome >> bem.categoria >> bem.dataAquisicao >> bem.peso) {
            // Verifica se a categoria é 'imovel' para ler o endereço
            if (bem.categoria == "imovel") {
                getline(arquivo, bem.endereco); // Leitura do endereço com espaços
            }
            bens.push_back(bem);
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
    return bens;
}

// Função para escrever os registros dos bens em um arquivo
void escreverRegistros(const vector<Bem>& bens) {
    ofstream arquivo("bens.txt");
    if (arquivo.is_open()) {
        for (int i = 0; i < bens.size(); ++i) {
            arquivo << bens[i].nome << " " << bens[i].categoria << " " << bens[i].dataAquisicao << " " << bens[i].peso;
            if (bens[i].categoria == "imovel") {
                arquivo << " " << bens[i].endereco;
            }
            arquivo << endl;
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo para escrita." << endl;
    }
}

// Função para adicionar um novo bem ao vetor de bens
void adicionarBem(vector<Bem>& bens) {
    Bem novoBem;
    cout << "Digite o nome do bem: ";
    getline(cin, novoBem.nome); // Leitura do nome com espacos
    cout << "Digite a categoria do bem: ";
    cin >> novoBem.categoria;
    cout << "Digite a data de aquisicao do bem: ";
    cin >> novoBem.dataAquisicao;
    cout << "Digite o peso do bem: ";
    cin >> novoBem.peso;
    cin.ignore(); // Limpar o buffer do teclado
    if (novoBem.categoria == "imovel") {
        cout << "Digite o endereco do bem: ";
        getline(cin, novoBem.endereco); // Leitura do endereco com espacos
    }
    bens.push_back(novoBem);
}

// Função para editar um bem existente
void editarBem(vector<Bem>& bens) {
    string nomeBem;
    cout << "Digite o nome do bem que deseja editar: ";
    getline(cin, nomeBem); // Leitura do nome com espacos
    for (int i = 0; i < bens.size(); ++i) {
        if (bens[i].nome == nomeBem) {
            cout << "Digite o novo nome do bem: ";
            getline(cin, bens[i].nome); // Leitura do nome com espacos
            cout << "Digite a nova categoria do bem: ";
            cin >> bens[i].categoria;
            cout << "Digite a nova data de aquisicao do bem: ";
            cin >> bens[i].dataAquisicao;
            cout << "Digite o novo peso do bem: ";
            cin >> bens[i].peso;
            cin.ignore(); // Limpar o buffer do teclado
            if (bens[i].categoria == "imovel") {
                cout << "Digite o novo endereco do bem: ";
                getline(cin, bens[i].endereco); // Leitura do endereco com espacos
            }
            cout << "Bem editado com sucesso." << endl;
            return;
        }
    }
    cout << "Bem nao encontrado." << endl;
}

// Função para excluir um bem existente
void excluirBem(vector<Bem>& bens) {
    string nomeBem;
    cout << "Digite o nome do bem que deseja excluir: ";
    getline(cin, nomeBem); // Leitura do nome com espacos
    for (int i = 0; i < bens.size(); ++i) {
        if (bens[i].nome == nomeBem) {
            bens.erase(bens.begin() + i);
            cout << "Bem excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Bem nao encontrado." << endl;
}

// Função para pesquisar bens por nome
void pesquisarPorNome(const vector<Bem>& bens) {
    string nomeBem;
    cout << "Digite o nome do bem que deseja pesquisar: ";
    getline(cin, nomeBem); // Leitura do nome com espacos
    for (int i = 0; i < bens.size(); ++i) {
        if (bens[i].nome == nomeBem) {
            cout << "Bem encontrado:" << endl;
            cout << "Nome: " << bens[i].nome << ", Categoria: " << bens[i].categoria
                 << ", Data de Aquisicao: " << bens[i].dataAquisicao << ", Peso: " << bens[i].peso;
            if (bens[i].categoria == "imovel") {
                cout << ", Endereco: " << bens[i].endereco;
            }
            cout << endl;
            return;
        }
    }
    cout << "Bem nao encontrado." << endl;
}

// Função para exibir os bens cadastrados
void exibirBens(const vector<Bem>& bens) {
    if (bens.empty()) {
        cout << "Nenhum bem cadastrado." << endl;
    } else {
        cout << "Bens cadastrados:" << endl;
        for (int i = 0; i < bens.size(); ++i) {
            cout << "Nome: " << bens[i].nome << ", Categoria: " << bens[i].categoria
                 << ", Data de Aquisicao: " << bens[i].dataAquisicao << ", Peso: " << bens[i].peso;
            if (bens[i].categoria == "imovel") {
                cout << ", Endereco: " << bens[i].endereco;
            }
            cout << endl;
        }
    }
}

int main() {
    vector<Bem> bens = lerRegistros();
    int opcao;
    do {
        system("cls"); // Limpar a tela

        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Adicionar novo bem" << endl;
        cout << "2. Editar bem existente" << endl;
        cout << "3. Excluir bem existente" << endl;
        cout << "4. Pesquisar bem por nome" << endl;
        cout << "5. Exibir bens cadastrados" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                system("cls");
                adicionarBem(bens);
                break;
            case 2:
                system("cls");
                editarBem(bens);
                break;
            case 3:
                system("cls");
                excluirBem(bens);
                break;
            case 4:
                system("cls");
                pesquisarPorNome(bens);
                break;
            case 5:
                system("cls");
                exibirBens(bens);
                break;
            case 6:
                system("cls");
                escreverRegistros(bens);
                cout << "Programa encerrado." << endl;
                break;
            default:
                cout << "Opcao invalida. Por favor, escolha uma opcao valida." << endl;
        }

        cout << "\nPressione Enter para continuar...";
        cin.ignore();
    } while (opcao != 6);

    return 0;
}

