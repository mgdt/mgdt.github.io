if (!(localStorage.getItem('mainObj'))) {
    let mainObj = {
        arr: [],
    }
    localStorage.setItem('mainObj', JSON.stringify(mainObj));

}

function addTask(task) {
    let mainObj = JSON.parse(localStorage.getItem('mainObj'));
    let elem = {
        text: task,
        completed: false,
    };
    mainObj.arr.push(elem);
    localStorage.setItem('mainObj', JSON.stringify(mainObj));
}

function deleteTask(taskIndex) {
    let mainObj = JSON.parse(localStorage.getItem('mainObj'));
    mainObj.arr.splice(taskIndex, 1);
    localStorage.setItem('mainObj', JSON.stringify(mainObj));
}

function completeTask(taskIndex) {
    let mainObj = JSON.parse(localStorage.getItem('mainObj'));
    mainObj.arr[taskIndex].completed = true;
    localStorage.setItem('mainObj', JSON.stringify(mainObj));
}

let mainList = document.querySelector('.list');

function fillContent() {
    let mainObj = JSON.parse(localStorage.getItem('mainObj'));
    mainList.innerHTML = '';
    mainObj.arr.forEach(item => {
        let listItem = document.createElement('li');
        listItem.classList.add('list-item');
        if(item.completed) {
            listItem.classList.add('list-item-completed');
        }

        let listItemText = document.createElement('span');
        listItemText.textContent = item.text;

        let closeBtn = document.createElement('div');
        closeBtn.innerHTML = `&times;`;

        listItem.appendChild(listItemText);
        listItem.appendChild(closeBtn);

        mainList.appendChild(listItem);
    });
}

fillContent();

let addInp = document.querySelector('.add-inp');
let addBtn = document.querySelector('.add-btn');
let addForm = document.querySelector('.add-form');

addForm.addEventListener('submit', (event) => {
    event.preventDefault();
    addTask(addInp.value)
    window.location.reload();
});

let listItems = document.querySelectorAll('.list li');

listItems.forEach((item, index) => {
    listItems = document.querySelectorAll('.list li');
    let itemText = item.querySelector('span');
    let itemClose = item.querySelector('div');
    itemText.addEventListener('click', () => {
        completeTask(index);
        window.location.reload();
    });
    itemClose.addEventListener('click', () => {
        deleteTask(index);
        window.location.reload();
    });
});