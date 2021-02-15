О приложении.
=======
Реализация консольного приложения калькулятор. Программа просит ввести строку, являющуюся математическим выражением и состоящим из целых и вещественных чисел (с различными десятичными разделителями) и знаков действий "+", "-", "*" и "/". После нажатия клавиши "Enter" приложение выводит результат вычисления.

Алгоритм работы приложения.
=======
По задумке приложение должно построить синтаксическое дерево, листьями которого будут являться числа, а вершинами математические действия. 

### Алгоритм построения синтаксического дерева.

На каждом шаге вершиной выбирается операция, которая должна выполниться последней, а ее ответвлениями - выражения находящиеся справа и слева от текущего символа. Действуя таким образом на последнем шаге будет получено дерево, корнем которого, будет самый последний шаг вычисления, а листьями только числа.

Для построения дерева потребуется функция, которая находит операцию, выполняющейся последней в данном выражении. Для ее реализации достаточно дважды пройтись по выражению справа-налево: в первый раз в поисках "слабых" знаков ("+" и "-"), а во второй, попытаться найти "сильные" ("*" и "/"). Успехом будет являться нахождение такого символа операции находящегося не в скобках. Если поиск не увенчался успехом, то перед нами либо число, либо выражение со скобками. В первом случае, будем считать что мы нашли лист, а во втором отбросим внешние скобки.

### Алгоритм вычисления результата.

При такой структуре построения выражения функция вызова расчета будет спускаться от корня к листьям. Каждая вершина передаст выполнение дочерним компонентам слева направо и произведет математическое действие, которое заменяет данная вершина, со значениями, вернувшимися от потомков. Когда вызов дойдет до листьев, они вернут значения определенных чисел.
Таким образом, самым первым выполненным математическим действием будет то, которое находится в синтаксическом дереве слева в последнем слое, так как в него раньше вернутся оба операнда. Построение дерева с конца гарантирует, что этим действием будет то, которое должно выполниться первым.

Для построения такой структуры потребуется возможность скрыть от вершины конкретный тип его потомков, будь то другая вершина или же число.

Описание структуры приложения. 
=======

Для создания такой структуры потребуется использовать паттерн проектирования "Компановщик". Для этого были реализованы три класса:
- <code>Calculatable</code> - являющийся общим интерфейсом для следующих двух классов и позволяющий обращаться к ним единообразно. Имеет два метода <code>clear()</code>, освобождающий память и <code>calculate()</code> - для вычисления результата;
- <code>Number</code> - лист дерева, в данном случае число;
- <code>Expression</code> - вершина, в данном случае математическая операция, контейнер для других объектов (таких же контейнеров или чисел), которым будет передаваться выполнение.

Построением дерева по описанному выше алгоритму, будет заниматься объект класса <code>Parser</code>.

Вычислением займется объект класса <code>Calculator</code>, а именно метод <code>calculate(Calculatable* expression)</code>.
