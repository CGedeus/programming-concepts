let array = ["Superman", {name : "Batman"}, true, function(){alert("Marvel!!!")}];
let teams = ["LA Lakers", "B/altimore Ravens", "Miami Heat", "FL Marlins"];

// So, the simplest way to clear the array is: arr.length = 0;.
// Excersize #4 for of loops
for (team of teams)
{
    console.log(team);
}

// Excersize #4 for in loops
for (team in teams)
{
    console.log(team);
}


// Fix later
// var matrix = [3][3];
// for (var outer = 0; outer < 3; outer++)
// {
//     for (var inner = 0; inner < 3; inner++)
//     {
//         console.log(matrix[outer][inner]);
//     }
// }

// Excersize #3 push & pop
// let item = array.pop();
// alert(item);
// alert(array);
// array.push("$$$$");    // The call fruits.push(...) is equal to fruits[fruits.length] = ....
// array[array.length] = "*****";
// alert(array);

// Excersize #2
// alert(array[array.length - 1]());
// alert(array.at(-2));
// alert(array.at(-3).name);   // .at() gets the length of the array minus the number specified

// Excersize #1
// alert(array[0]);
// alert(array[1].name);
// alert(array[2]);
// array[3]();