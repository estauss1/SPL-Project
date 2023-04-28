// Creates matrices from input file and measures time it takes
// to find the product of the matrices
// Eric Stauss
// 4/28/2023

const NUMBER_OF_ROWS_ONE = 250;
const NUMBER_OF_COLUMNS_ONE = 250;
const NUMBER_OF_ROWS_TWO = 250;
const NUMBER_OF_COLUMNS_TWO = 250;

// dynamically typed unlike c++ so type of variable is associated
// with runtime values. Variable can be bound to different types
let matrixOne;
let matrixTwo;

// get numbers from text file to create matrices
fetch('matrix-input.txt')
    .then(response => response.text())
    .then(text => {
        const rows = text.trim().split('\n');
        matrixOne =
            rows.slice(0, NUMBER_OF_ROWS_ONE).map(row => row.trim().split(' ').map(Number));
        matrixTwo =
            rows.slice(NUMBER_OF_ROWS_ONE).map(row => row.trim().split(' ').map(Number));
        console.log(matrix1);
        console.log(matrix2);
    })
    .catch(error => console.log(error));

let matrixProduct = [];
for (let i = 0; i < NUMBER_OF_ROWS_ONE; ++i) {
    let row = [];
    for (let j = 0; j < NUMBER_OF_COLUMNS_TWO; ++j) {
        row.push(0);
    }
    matrixProduct.push(row);
}
console.log(matrixProduct);
window.onload = function () {
    const butt = document.getElementById('butt');
    butt.addEventListener('click', calcProduct);

    const directions = document.getElementById('directions');
    directions.textContent = `click start test to measure the time it takes to`
        + ` multiply a ${NUMBER_OF_ROWS_ONE}x${NUMBER_OF_COLUMNS_ONE} matrix with`
        + ` a ${NUMBER_OF_ROWS_TWO}x${NUMBER_OF_COLUMNS_TWO} matrix`

    const calcTime = document.getElementById('calc-time');

    // measures time it takes to calculate the product matrix
    // in basically exact same way as c++ file does except it
    // is significantly slower due to javascript being an 
    // intepretted language and c++ is compiled 
    function calcProduct() {
        const startTime = performance.now();
        let productElement = 0
        for (let oneRow = 0; oneRow < NUMBER_OF_COLUMNS_ONE; ++oneRow) {
            for (let twoColumn = 0; twoColumn < NUMBER_OF_COLUMNS_TWO; ++twoColumn) {
                for (let oneColumn = 0, twoRow = 0; oneColumn < NUMBER_OF_COLUMNS_ONE
                    && twoRow < NUMBER_OF_COLUMNS_TWO; ++oneColumn, ++twoRow) {
                    productElement += (matrixOne[oneRow][oneColumn]
                        * matrixTwo[twoRow][twoColumn]);
                }
                matrixProduct[oneRow][twoColumn] = productElement;
                productElement = 0;
            }
        }
        const endTime = performance.now();
        const duration = endTime - startTime;
        calcTime.textContent = `It took ${duration}ms to calculate the `
            + `${NUMBER_OF_ROWS_ONE}x${NUMBER_OF_COLUMNS_TWO} product matrix.`
    }
}
// notice how there is no calls to delete like in c++ file
// memory management is done automatically in javascript and not
// explicitly by programmer
