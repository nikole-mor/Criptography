document.querySelectorAll('.dropdown-btn').forEach(button => {
    button.addEventListener('click', function () {
        const dropdownContent = this.nextElementSibling;
        const arrow = this.querySelector('.arrow');
        
        dropdownContent.style.display = 
            dropdownContent.style.display === 'block' ? 'none' : 'block';
        
        // Toggle arrow rotation
        this.classList.toggle('active');
    });
});
