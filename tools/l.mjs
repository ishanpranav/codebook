function saveToDatabase() {}
function User(username) {
    this.username = username;
}

User.prototype.save = function() {
    // assuming that saveToDatabase function exists
    saveToDatabase();
    console.log('saving ' + this.username);
};

const user = User('pizza4life');

console.log(username);