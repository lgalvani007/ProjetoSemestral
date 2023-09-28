import os

ui_files = ["Menu.ui", "Velocidade.ui", "Posicao.ui", "Controladores.ui"]

for ui_file in ui_files:
    output_py_file = os.path.splitext(ui_file)[0] + ".py"
    command = f'pyuic5 "{ui_file}" -o "{output_py_file}" -x'
    os.system(command)