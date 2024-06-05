import { Link, useLocation } from 'react-router-dom';
import styled from 'styled-components';
import color from '../../utils/colors';
import image from '../../Assets/dark-logo.png';
import light_image from '../../Assets/light-logo.png';
import { ThemeContext } from '../../utils/context';
import { useContext } from 'react';

const StyledLink = styled(Link)`
  padding: 15px;
  color: ${({ isDarkMode }) => (isDarkMode ? `${color.secondary}` : `${color.primary}`)};
  text-decoration: none;
  font-size: 18px;
  position: relative;
  z-index: 1;
  transition: transform 0.3s, background-color 0.3s, color 0.3s;

  ${(props) =>
    props.$isFullLink &&
    `
      color: white;
      height: 20px;
      border-radius: 30px;
      margin-left: auto;
      background-color: ${color.primary};
  `}
  &:hover {
    transform: scale(1.1);
  }
`;

const StyledHeader = styled.div`
  text-align: right;
  padding: 12px;
  display: flex;
  flex-direction: row;
  position: relative;
`;

const StyledLogo = styled.img`
  width: 150px;
  height: 60px;
  margin-right: auto;
`;

const Indicator = styled.div`
  position: absolute;
  bottom: 0;
  left: ${({ position }) => position}px;
  width: 100px; /* Ajustez la largeur selon vos besoins */
  height: 5px; /* Ajustez la hauteur selon vos besoins */
  background-color: ${({ isDarkMode }) => (isDarkMode ? `${color.secondary}` : `${color.primary}`)};
  transition: left 0.3s ease;
  z-index: 0;
`;

function Header() {
  const { theme } = useContext(ThemeContext);
  const location = useLocation();
  
  const links = [
    { path: '/', label: 'Accueil' },
    { path: '/survey/1', label: 'Questionnaire' },
    { path: '/freelance', label: 'Freelances' }
  ];

  const activeIndex = links.findIndex(link => link.path === location.pathname);
  const indicatorPosition = activeIndex * 120 + 1100; // Ajustez le calcul de la position en fonction de la largeur des liens et des marges/paddings

  return (
    <StyledHeader>
      <StyledLogo src={theme === 'dark' ? light_image : image} alt='logo'></StyledLogo>
      {links.map((link, index) => (
        <StyledLink key={link.path} isDarkMode={theme === 'dark'} to={link.path} $isFullLink={link.path === '/'}>
          {link.label}
        </StyledLink>
      ))}
      <Indicator position={indicatorPosition} isDarkMode={theme === 'dark'} />
    </StyledHeader>
  );
}

export default Header;
