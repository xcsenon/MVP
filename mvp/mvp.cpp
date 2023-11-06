#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    class Model {
    public:
        string GetData() {
            return data;
        }

        void SetData(const string& newData) {
            data = newData;
        }

    private:
        string data;
    };

    class View {
    public:
        void ShowData(const string& data) {
            cout << "Дані: " << data << endl;
        }

        string GetInput(const string& prompt) {
            string input;
            cout << prompt;
            getline(cin, input);
            return input;
        }
    };

    class Presenter {
    public:
        Presenter(Model& model, View& view) : model(model), view(view) {}

        void Run() {
            string data = model.GetData();
            view.ShowData(data);

            string newData = view.GetInput("Введіть нові дані: ");
            model.SetData(newData);
            view.ShowData(newData);
        }

    private:
        Model& model;
        View& view;
    };

    Model model;
    View view;
    Presenter presenter(model, view);


    string initialData = view.GetInput("Введіть дані: ");
    model.SetData(initialData);

    presenter.Run();

    return 0;
}
