
// scroll button
var scrollButton = document.querySelector('.go-top');


scrollButton.classList.remove('show');


window.addEventListener('scroll', function() {
    if (window.pageYOffset > 150) {
        scrollButton.classList.add('show');
    } else {
    scrollButton.classList.remove('show');
    }
});


scrollButton.addEventListener('click', function() {
    window.scrollTo({
    top: 0,
    }
    );
});

// scroll button


// active page

var url = window.location.href;

var links = document.querySelectorAll('nav ul li a');

links.forEach(function(link) {
    if (link.href === url) {
    link.classList.add('active');
    } else {
    link.classList.remove('active');
}
});
// active page


// about us scripts 
//  email
document.addEventListener('DOMContentLoaded', function() {
    var emailDiv = document.getElementById('email');
    emailDiv.addEventListener('click', function() {
        window.location.href = 'mailto:safir@travel.com';
    });
});


// phone call
document.addEventListener('DOMContentLoaded', function() {
    var phoneDiv = document.getElementById('phone');
    phoneDiv.addEventListener('click', function() {
        window.location.href = 'tel:+213696398996';
});
});


// adress location
document.addEventListener('DOMContentLoaded', function() {
var addressDiv = document.getElementById('address');
addressDiv.addEventListener('click', function() {
    var mapsUrl = 'https://www.google.fr/maps/place/%D8%A7%D9%84%D8%AD%D9%82%D9%86%D8%A9%E2%80%AD/@36.8140958,7.7172386,265m/data=!3m1!1e3!4m15!1m8!3m7!1s0x12f00917d693ae31:0xdb53c7fbace30acc!2sSidi+Amar!3b1!8m2!3d36.820313!4d7.7151367!16s%2Fm%2F03wdg77!3m5!1s0x12f009a839e93d9b:0x5f46caae0432cd1f!8m2!3d36.8139815!4d7.718454!16s%2Fg%2F11kbns54m1';
    window.open(mapsUrl, '_blank');
});
});




// our services


var hotelReservationDiv = document.getElementById("hotelReservation");
var organizedTripsDiv = document.getElementById("organizedTrips");
var bookFlightsDiv = document.getElementById("bookFlights");

hotelReservationDiv.addEventListener("click", function () {
    window.location.href = "hotels.html";
});

organizedTripsDiv.addEventListener("click", function () {
    window.location.href = "tours.html";
});

bookFlightsDiv.addEventListener("click", function () {
    window.location.href = "destinations.html";
});
