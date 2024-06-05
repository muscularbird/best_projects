import React from 'react';
import styled from 'styled-components';
import colors from '../../utils/colors';

const FormContainer = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 2em;
    background-color: ${colors.background};
    border-radius: 10px;
    box-shadow: 0 6px 9px rgba(0, 0, 0, 0.1);
    max-width: 400px;
    margin: 2em auto;

    @media (max-width: 768px) {
        padding: 1em;
        max-width: 100%;
    }
`;


const Title = styled.h2`
    margin-bottom: 1em;
    color: ${colors.primary};
`;

const StyledForm = styled.form`
    display: flex;
    flex-direction: column;
    width: 100%;
`;

const StyledLabel = styled.label`
    display: flex;
    flex-direction: column;
    align-items: center;
    width: 100%;
    margin-bottom: 0.5em;
    color: ${colors.secondary};
    font-size: 1em;
`;

const StyledInput = styled.input`
    display: flex;
    align-items: center;
    padding: 0.5em;
    margin-bottom: 1em;
    border: 1px solid ${colors.primary};
    border-radius: 5px;
    font-size: 1em;
    &:focus {
        border-color: ${colors.secondary};
        outline: none;
        box-shadow: 0 0 5px ${colors.secondary};
    }
`;

const StyledMessageInput = styled.textarea`
    display: flex;
    // align-items: center;
    width: 25em;
    height: 5em;
    padding: 0.5em;
    margin-bottom: 1em;
    border: 1px solid ${colors.primary};
    border-radius: 5px;
    font-size: 1em;
    resize: vertical;
    &:focus {
        border-color: ${colors.secondary};
        outline: none;
        box-shadow: 0 0 5px ${colors.secondary};
    }
`;

const SubmitButton = styled.input`
    padding: 0.75em;
    background-color: ${colors.primary};
    color: white;
    border: none;
    border-radius: 5px;
    font-size: 1em;
    cursor: pointer;
    transition: background-color 0.3s;
    &:hover {
        background-color: ${colors.secondary};
    }
`;

function Contact() {
    return (
      <FormContainer>
        <Title>Contact Us</Title>
        <StyledForm>
          <StyledLabel>
            Email:
            <StyledInput type="text" name="email" defaultValue="example@example.com"/>
          </StyledLabel>
          <StyledLabel>
            Name:
            <StyledInput type="text" name="Name" />
          </StyledLabel>
          <StyledLabel>
            Your Message:
            <StyledMessageInput type="text" name="Your message" defaultValue="Say us everything"/>
          </StyledLabel>
          <SubmitButton type="submit" value="Submit" />
        </StyledForm>
      </FormContainer>
    );
}

export default Contact;
