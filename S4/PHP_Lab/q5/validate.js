function showsubmitbuttonerror() {
  let submitbtn = document.getElementById("submitbutton");
  if (!submitbtn.disabled) {
    return;
  }
  submitbtn.title = "Please fill up a valid form!";
}

function validate_form() {
  input_errors = 0;
  input_errors = input_errors + validate_name();
  input_errors = input_errors + validate_address();
  input_errors = input_errors + validate_bloodgroup();
  input_errors = input_errors + validate_dob();
  input_errors = input_errors + validate_aadharnum();
  input_errors = input_errors + validate_number();
  input_errors = input_errors + validate_email();
  console.log("Number of error inputs: " + input_errors);
  if (input_errors == 0) {
    document.getElementById("submitbutton").disabled = false;
  } else {
    document.getElementById("submitbutton").disabled = true;
  }
}

function validate_name() {
  labeltag = document.getElementById("l_name");
  input_field = document.getElementById("nameid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Name: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length < 3) {
    labeltag.innerHTML = 'Name: <span style="color:red">*</span>';
    input_field.title =
      "Name length is less than 3 characters,\n Enter a real name!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Name:";
  return 0;
}
function validate_address() {
  labeltag = document.getElementById("l_address");
  input_field = document.getElementById("addressid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Address: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length < 10) {
    labeltag.innerHTML = 'Address: <span style="color:red">*</span>';
    input_field.title = "Address length is less than 10 characters!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Address:";
  return 0;
}
function validate_bloodgroup() {
  labeltag = document.getElementById("l_bloodgroup");
  input_field = document.getElementById("bloodgroupid");
  value = input_field.value;
  console.log(value);
  if (value === "null") {
    labeltag.innerHTML = 'Blood Group: <span style="color:red">*</span>';
    input_field.title = "Select a blood group!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Blood Group:";
  return 0;
}
function validate_dob() {
  labeltag = document.getElementById("l_dob");
  input_field = document.getElementById("dobid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Date Of Birth: <span style="color:red">*</span>';
    return 1;
  }
  if (isNaN(new Date(value))) {
    labeltag.innerHTML = 'Date Of Birth: <span style="color:red">*</span>';
    input_field.title = "Enter a valid date!";
    return 1;
  }
  let age = new Date().getFullYear() - new Date(value).getFullYear();
  let m = new Date().getMonth() - new Date(value).getMonth();
  if (m < 0 || (m === 0 && new Date().getDate() < new Date(value).getDate())) {
    age--;
  }
  if (age < 18) {
    labeltag.innerHTML = 'Date Of Birth: <span style="color:red">*</span>';
    input_field.title = "Age should be 18 or higher!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Date Of Birth:";
  return 0;
}

function validate_aadharnum() {
  labeltag = document.getElementById("l_aadharnum");
  input_field = document.getElementById("aadharnumid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Aadhar Number: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length !== 12) {
    labeltag.innerHTML = 'Aadhar Number: <span style="color:red">*</span>';
    input_field.title = "A valid Aadhar number has 12 digits!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Aadhar Number:";
  return 0;
}

function validate_number() {
  labeltag = document.getElementById("l_mobnum");
  input_field = document.getElementById("mobnumid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Mobile Number: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length !== 10) {
    labeltag.innerHTML = 'Mobile Number: <span style="color:red">*</span>';
    input_field.title = "A valid Mobile number has 10 digits!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Mobile Number:";
  return 0;
}

function validate_email() {
  let pattern =
    /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  labeltag = document.getElementById("l_email");
  input_field = document.getElementById("emailid");
  value = input_field.value;
  if (value === "") {
    labeltag.innerHTML = 'Email: <span style="color:red">*</span>';
    return 1;
  }
  console.log(value.match(pattern));
  if (!value.match(pattern)) {
    labeltag.innerHTML = 'Email: <span style="color:red">*</span>';
    input_field.title = "Is not a valid Email format!";
    return 1;
  }

  input_field.title = "";
  labeltag.innerHTML = "Email:";
  return 0;
}
