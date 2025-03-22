function validate_form() {
  input_errors = 0;
  input_errors = input_errors + validate_empcode();
  input_errors = input_errors + validate_name();
  input_errors = input_errors + validate_address();
  input_errors = input_errors + validate_dob();
  input_errors = input_errors + validate_gender();
  input_errors = input_errors + validate_number();
  input_errors = input_errors + validate_email();
  console.log("Number of error inputs: " + input_errors);
  if (input_errors == 0) {
    document.getElementById("submitbutton").disabled = false;
  } else {
    document.getElementById("submitbutton").disabled = true;
  }
}

function validate_empcode() {
  labeltag = document.getElementById("l_empcode");
  value = document.getElementById("empcodeid").value;
  if (value === "") {
    labeltag.innerHTML = 'Employee Code: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Employee Code:";
  return 0;
}
function validate_name() {
  labeltag = document.getElementById("l_name");
  value = document.getElementById("nameid").value;
  if (value === "") {
    labeltag.innerHTML = 'Name: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length < 3) {
    labeltag.innerHTML = 'Name: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Name:";
  return 0;
}
function validate_address() {
  labeltag = document.getElementById("l_address");
  value = document.getElementById("addressid").value;
  if (value === "") {
    labeltag.innerHTML = 'Address: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length < 10) {
    labeltag.innerHTML = 'Address: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Address:";
  return 0;
}
function validate_dob() {
  labeltag = document.getElementById("l_dob");
  value = document.getElementById("dobid").value;
  if (value === "") {
    labeltag.innerHTML = 'Date Of Birth: <span style="color:red">*</span>';
    return 1;
  }
  if (isNaN(new Date(value))) {
    labeltag.innerHTML = 'Date Of Birth: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Date Of Birth:";
  return 0;
}
function validate_gender() {
  labeltag = document.getElementById("l_gender");
  malechecked = document.getElementById("maleradioid").checked;
  femalechecked = document.getElementById("femaleradioid").checked;
  if (!malechecked && !femalechecked) {
    labeltag.innerHTML = 'Gender: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Gender:";
  return 0;
}

function validate_number() {
  labeltag = document.getElementById("l_mobnum");
  value = document.getElementById("mobnumid").value;
  if (value === "") {
    labeltag.innerHTML = 'Mobile Number: <span style="color:red">*</span>';
    return 1;
  }
  if (value.length < 10) {
    labeltag.innerHTML = 'Mobile Number: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Mobile Number:";
  return 0;
}

function validate_email() {
  let pattern =
    /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  labeltag = document.getElementById("l_email");
  value = document.getElementById("emailid").value;
  if (value === "") {
    labeltag.innerHTML = 'Email: <span style="color:red">*</span>';
    return 1;
  }
  console.log(value.match(pattern));
  if (!value.match(pattern)) {
    labeltag.innerHTML = 'Email: <span style="color:red">*</span>';
    return 1;
  }

  labeltag.innerHTML = "Email:";
  return 0;
}
