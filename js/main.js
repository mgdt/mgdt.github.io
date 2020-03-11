var teamNext = document.querySelector('.team__next');
var teamPrev = document.querySelector('.team__prev');
var teamItems = document.querySelectorAll('.team__item');
var teamPagWrap = document.querySelector('.team__pag');
var pos = 0;

for (var i = 0; i < teamItems.length; i++) {
    var teamPag = document.createElement('li');
    teamPag.classList.add('team__pag-elem')
    teamPagWrap.appendChild(teamPag);
}

var teamPagElems = document.querySelectorAll('.team__pag-elem');
teamPagElems[0].classList.add('team__pag-elem--active');

function slide() {
    if(pos == -1) {
        pos = teamItems.length-1;
    } else if(pos == teamItems.length) {
        pos = 0;
    }

    if(pos == teamItems.length-1) {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[teamItems.length-2].classList.add('team-item-prev');
        teamItems[teamItems.length-1].classList.add('team-item-active');
        teamItems[0].classList.add('team-item-next');
    } else if(pos == 0) {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[teamItems.length-1].classList.add('team-item-prev');
        teamItems[0].classList.add('team-item-active');
        teamItems[1].classList.add('team-item-next');
    } else {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[pos-1].classList.add('team-item-prev');
        teamItems[pos].classList.add('team-item-active');
        teamItems[pos+1].classList.add('team-item-next');
    }
    document.querySelector('.team__pag-elem--active').classList.remove('team__pag-elem--active');
    teamPagElems[pos].classList.add('team__pag-elem--active');

}

teamNext.addEventListener('click', function() {
    pos++;
    slide(pos);
});

teamPrev.addEventListener('click', function() {
    pos--;
    slide(pos);
});

function slideCurrent(arg) {
    if(arg == teamPagElems.length-1) {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[teamItems.length-2].classList.add('team-item-prev');
        teamItems[teamItems.length-1].classList.add('team-item-active');
        teamItems[0].classList.add('team-item-next');
    } else if(arg == 0) {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[teamItems.length-1].classList.add('team-item-prev');
        teamItems[0].classList.add('team-item-active');
        teamItems[1].classList.add('team-item-next');
    } else {
        document.querySelector('.team-item-prev').classList.remove('team-item-prev');
        document.querySelector('.team-item-active').classList.remove('team-item-active');
        document.querySelector('.team-item-next').classList.remove('team-item-next');

        teamItems[arg-1].classList.add('team-item-prev');
        teamItems[arg].classList.add('team-item-active');
        teamItems[arg+1].classList.add('team-item-next');
    }
}

teamPagElems.forEach(function(item, index){
    item.addEventListener('click', function() {
        slideCurrent(index);
        document.querySelector('.team__pag-elem--active').classList.remove('team__pag-elem--active');
        teamPagElems[index].classList.add('team__pag-elem--active');
    });
});

teamItems.forEach(function(item, index) {
    item.addEventListener('click', function() {
        slideCurrent(index);
        document.querySelector('.team__pag-elem--active').classList.remove('team__pag-elem--active');
        teamPagElems[index].classList.add('team__pag-elem--active');
    });
});

var faqItems = document.querySelectorAll('.faq__item');
$(faqItems).each(function(index, item) {
    var faqBtn = item.querySelector('.faq__btn');
    var faqText = item.querySelector('.faq__text');
    $(faqBtn).click(function() {
        if(faqBtn.textContent == '+') {
            faqBtn.textContent = '—';
        } else {
            faqBtn.textContent = '+';
        }
        $(faqText).slideToggle(200);
    });
});

var popups = document.querySelectorAll('.popup');

popups.forEach(function(item, index) {
    var popupChecks = item.querySelectorAll('.popup__item');
    if(popupChecks) {
        popupChecks.forEach(function(elem) {
            elem.addEventListener('click', function() {
                popupActive = item.querySelector('.popup__item-active');
                if(popupActive) {
                    popupActive.classList.remove('popup__item-active');
                    elem.classList.add('popup__item-active');
                } else {
                    elem.classList.add('popup__item-active');
                }
            });
        });
    }

    var popupInp = item.querySelector('.popup__input-wrap');
    if(popupInp) {
        popupInpInner = document.querySelector('.popup__input');
        popupInpInner.addEventListener('change', function() {
            if(popupInpInner.value.length > 0) {
                popupInp.classList.add('popup__item-active')
            } else {
                popupInp.classList.remove('popup__item-active');
            }
        });
    }

    var popupNext = item.querySelector('.popup__btn-next');
    if(popupNext) {
        popupNext.addEventListener('click', function() {
            var popupActive = item.querySelector('.popup__item-active');
            if(popupActive) {
                popups[index].style.display = 'none';
                popups[index + 1].style.display = '';
            }
        }); 
    }
    var popupPrev = item.querySelector('.popup__btn-prev');
    if(popupPrev) {
        popupPrev.addEventListener('click', function() {
            popups[index].style.display = 'none';
            popups[index - 1].style.display = '';
        }); 
    }

});


var popupLastForm = document.querySelector('.popup-last__form');
popupLastForm.addEventListener('submit', function(event) {
    event.preventDefault();
    popupWrap.style.display = '';
    popupThank.style.display = '';
});

var analysForm = document.querySelector('.analys__form');
analysForm.addEventListener('submit', function(event) {
    event.preventDefault();
    popupWrap.style.display = '';
    popupThank.style.display = '';
});

var popupThank = document.querySelector('.popup-thank');

var popupClose = document.querySelector('.popup-thank__close');

var popupWrap = document.querySelector('.popup-wrap');
popupWrap.addEventListener('click', function() {
    popups.forEach(function(item) {
        item.style.display = 'none';
    });
    popupWrap.style.display = 'none';
    popupThank.style.display = 'none';
});

popupClose.addEventListener('click', function() {
    popups.forEach(function(item) {
        item.style.display = 'none';
    });
    popupWrap.style.display = 'none';
    popupThank.style.display = 'none';
});

function popup() {
    popupWrap.style.display = '';
    popups[0].style.display = '';
}