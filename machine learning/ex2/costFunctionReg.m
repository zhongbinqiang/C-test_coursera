function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
h = sigmoid(X*theta);%hypothesis
n = size(theta,1);%number of features + 1
J = (1/m)*(-1*(y'*log(h)) - (1-y)'*log(1-h));%cost function without regularing
for i = 2:n,%notice: theta(1) should not be regularizing.
    J = J + lambda/(2*m)*theta(i)^2;
end
grad(1) = (1/m)*X(:,1)'*(h - y);%notice: theta(1) should not be regularizing.
for j = 2:n,
   grad(j) = (1/m)*X(:,j)'*(h - y) + (lambda/m)*theta(j);
end

% =============================================================

end
